#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/File/FSFile.hpp"
#include "Bubblewrap/Logs/Log.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Base/Resource.hpp"
#include "Bubblewrap/Data/ResourceList.hpp"
#include <cctype>
namespace Bubblewrap
{
	namespace Base
	{
		ObjectRegister::ObjectRegister()
		{
			LoadState_ = 0;
			LoadingPackage_ = false;
			LoadingResources_ = false;
		}

		ObjectRegister::~ObjectRegister()
		{
			for ( unsigned int Idx = 0; Idx < Objects_.size(); ++Idx )
			{
				delete Objects_[ Idx ];
			}
			Objects_.clear();

		}

		int ObjectRegister::RegisterObject( GoBase* Object )
		{
			Object->Id_ = NextId_++;

			Object->ObjectRegister_ = this;
			Object->Manager_ = Managers_;
			Objects_.push_back( Object );

			return Object->Id_;
		}

		GoBase* ObjectRegister::GetObject( int Id )
		{
			for ( unsigned int Idx = 0; Idx < Objects_.size(); ++Idx )
			{
				if ( Objects_[ Idx ]->Id_ == Id )
				{
					return Objects_[ Idx ];
				}
			}

			return nullptr;
		}

		void ObjectRegister::Update( float Dt )
		{
			for ( unsigned int Idx = 0; Idx < ParentlessItems_.size(); ++Idx )
			{
				ParentlessItems_[ Idx ]->Update( Dt );
			}
			CheckCollisions();
		}

		void ObjectRegister::CheckCollisions()
		{
			/*		for ( unsigned int Idx0 = 0; Idx0 < Objects_.size(); ++Idx0 )
			{
			for ( unsigned int Idx1 = Idx0 + 1; Idx1 < Objects_.size(); ++Idx1 )
			{
			GoBase* objA = Objects_[ Idx0 ];
			GoBase* objB = Objects_[ Idx1 ];
			if ( !objA->Collidable_ || !objB->Collidable_ )
			continue;
			if ( objA->Id() > objB->Id() )
			{
			objA = Objects_[ Idx1 ];
			objB = Objects_[ Idx0 ];
			}
			bool Colliding = CollisionSystem::DoCollide( objA, objB );

			if ( Colliding )
			{
			// Yay Colliding
			if ( !CollisionMap[ objA ][ objB ] )
			{
			CollisionMap[ objA ][ objB ] = true;
			objA->BeginCollision( objB );
			objB->BeginCollision( objA );
			}
			}
			else if ( CollisionMap[ objA ][ objB ] )
			{
			CollisionMap[ objA ][ objB ] = false;
			objA->EndCollision( objB );
			objB->EndCollision( objA );
			}
			}

			}/**/
		}

		void ObjectRegister::DestroyPhase()
		{
			DBool destroyObject;
			for ( unsigned int Idx = 0; Idx < Objects_.size(); ++Idx )
			{
				if ( Objects_[ Idx ]->Destroy_ )
				{
					// EvtMessage DestroyMessage( 0 /* TODO: Add Value*/ );
					// DestroyMessage.Data_ = &Objects_[ Idx ]->Id_;
					// RepeatMessage( DestroyMessage );
					Objects_[ Idx ]->OnDetach();
					if ( Objects_[ Idx ]->GetParentEntity() != nullptr )
					{
						Objects_[ Idx ]->GetParentEntity()->RemoveChild(Objects_[Idx ]);
					}
					destroyObject = true;
				}
			}
			if ( !destroyObject )
				return;

			for ( std::vector<GoBase*>::iterator iter = Objects_.begin(); iter != Objects_.end(); )
			{
				if ( ( *iter )->Destroy_ )
				{
					delete ( *iter );
					iter = Objects_.erase( iter );
				}
				else
					++iter;
			}
		}

		/*void ObjectRegister::RepeatMessage( EvtMessage  Message )
		{
		for ( unsigned int Idx = 0; Idx < Objects_.size(); ++Idx )
		{
		Objects_[ Idx ]->ReceiveMessage( Message );
		}
		for ( unsigned int Idx = 0; Idx < CallBacks_.size(); ++Idx )
		{
		CallBacks_[ Idx ]( Message );
		}
		}

		void ObjectRegister::AddReceiver( std::function< void( EvtMessage ) > Function )
		{
		CallBacks_.push_back( Function );
		}/**/

		void ObjectRegister::RegisterCreator( std::string Class, std::function < GoBase*( ) > Creator, std::function < GoBase*( Json::Value ) > CreatorJson,
			std::function< void( GoBase*, GoBase* ) > Copier, bool Override )
		{
			Logs::Log log( "ObjectRegister::RegisterCreator" );
			log.WriteLine( "Registering class: " + Class );
			if ( ( ClassGenerators_.find( Class ) != ClassGenerators_.end() ) && !Override )
			{
				log.WriteLine( "Overriding class: " + Class );
			}
			ClassGenerators_[ Class ].ClassGenerator_ = Creator;
			ClassGenerators_[ Class ].ClassGeneratorJson_ = CreatorJson;
			ClassGenerators_[ Class ].ClassCopier_ = Copier;
		}

		GoBase* ObjectRegister::CreateObject( std::string Type, Entity* Parent )
		{
			Logs::Log log( "ObjectRegister::CreateObject" );
			log.WriteLine( "CreateObject: " + Type + " (TYPE)" );
			IncLoad();

			GoBase* obj = ClassGenerators_[ Type ].ClassGenerator_();
			obj->Parent_ = Parent;
			RegisterObject( obj );
			if ( !( LoadingPackage_ || LoadingResources_ ))
			{
				log.WriteLine( "Sending to Attach" );
				char buffer[ 256 ];
				sprintf( buffer, "Id: %d", obj->Id() );
				log.WriteLine( buffer );
				ToAttach_.push_back( obj );
			}
			if ( Parent == nullptr )
			{
				ParentlessItems_.push_back( obj );
			}
			DecLoad();

			return obj;
		}

		GoBase* ObjectRegister::CreateObject( Json::Value Json, Entity* Parent )
		{
			IncLoad();
			Logs::Log log( "ObjectRegister::CreateObject" );
			log.WriteLine( "CreateObject: " + Json[ "type" ].asString() + " (JSON)" );
			std::string Type = Json[ "type" ].asString();
			GoBase* obj = ClassGenerators_[ Type ].ClassGeneratorJson_( Json );
			if ( !( LoadingPackage_ || LoadingResources_ ) )
				ToAttach_.push_back( obj );
			obj->Parent_ = Parent;
			RegisterObject( obj );
			if ( Parent == nullptr )
			{
				if ( LoadingPackage_ || LoadingResources_ )
				{
				}
				else
				{
					ParentlessItems_.push_back( obj );
				}
			}
			obj->Initialise( Json );
			if ( LoadingPackage_ && ( Parent == nullptr ) )
			{
				PackageObjects_[ CurrentPackage_ ][ obj->GetName() ] = obj;
			}
			else if ( LoadingResources_ && ( Parent == nullptr ) )
			{
				Resources_[ CurrentPackage_ ][ obj->GetName() ] = dynamic_cast<Resource*>(obj);
			}
			DecLoad();
			return obj;

		}

		void ObjectRegister::SetManager( Managers::Managers* Manager )
		{
			if ( Managers_ != nullptr )
			{
				assert( false && "DONT BE A DUMBASS" );
				return;
			}
			Managers_ = Manager;
		}

		void ObjectRegister::AttachItems()
		{
			Logs::Log log( "ObjectRegister::AttachItems" );
			log.WriteLine( "Calling attach" );
			if ( LoadingPackage_ || LoadingResources_)
			{
				assert( false );
			}
			unsigned int uCount = ToAttach_.size();
			for ( unsigned int Idx = 0; Idx < uCount; ++Idx )
			{
				ToAttach_[ Idx ]->OnAttach();
			}
			ToAttach_.clear();
		}

		void ObjectRegister::LoadPackage( std::string PackageFile )
		{
			Logs::Log log( "ObjectRegiser::LoadPackage (" + PackageFile + ")" );
			log.WriteLine( "Package Name: " + PackageFile );
			LoadingPackage_ = true;
			File::FiFSFile file( PackageFile );
			file.Open( File::FsMode::Read );

			std::string fileData = file.ReadAll();
			file.Close();
			Json::Value root;
			Json::Reader rdr;

			rdr.parse( fileData, root );

			CurrentPackage_ = root[ "name" ].asCString();

			Json::Value items = root[ "items" ];

			for ( unsigned int Idx = 0; Idx < items.size(); ++Idx )
			{
				CreateObject( items[ Idx ], nullptr );
			}

			LoadingPackage_ = false;

		}

		GoBase* ObjectRegister::LoadObject( std::string Name, Entity* Parent )
		{
			int split = Name.find_first_of( ':' );
			std::string package = Name.substr( 0, split );
			std::string name = Name.substr( split + 1 );
			return LoadObject( package, name, Parent );
		}

		GoBase* ObjectRegister::LoadObject( std::string PackageName, std::string Name, Entity* Parent )
		{
			IncLoad();

			Logs::Log log( "ObjectRegister::LoadObject {" + PackageName + ":" + Name + "}" );
			GoBase* base = PackageObjects_[ PackageName ][ Name ];

			GoBase* ret = CreateObject( base->TypeName(), Parent );
			ClassGenerators_[ base->TypeName() ].ClassCopier_( ret, base );

			DecLoad();

			return ret;

		}
		GoBase* ObjectRegister::CreateCopy( GoBase* Base, Entity* Parent )
		{
			GoBase* ret = CreateObject( Base->TypeName(), Parent );
			ClassGenerators_[ Base->TypeName() ].ClassCopier_( ret, Base );
			return ret;
		}

		void ObjectRegister::LogHierarchy()
		{
			Logs::Log log( "LogHierarchy" );
			for ( unsigned int Idx = 0; Idx < ParentlessItems_.size(); ++Idx )
			{
				Entity* ent = dynamic_cast<Entity*>( ParentlessItems_[ Idx ] );
				if ( ent != nullptr )
					ent->LogHierarchy();
				else
					log.WriteLine( ParentlessItems_[ Idx ]->GetName() + "{" + ParentlessItems_[ Idx ]->TypeName() + "}" );
			}
		}

		void ObjectRegister::IncLoad()
		{
			++LoadState_;
		}

		void ObjectRegister::DecLoad()
		{
			--LoadState_;
			if ( ( LoadState_ == 0 ) && ( !( LoadingPackage_ || LoadingResources_ ) ) )
			{
				AttachItems();
			}
		}

		Managers::Managers* ObjectRegister::GetManager()
		{
			return Managers_;
		}

		void ObjectRegister::LoadResources( std::string ResourceFile )
		{
			Logs::Log log( "ObjectRegiser::LoadResources (" + ResourceFile + ")" );
			log.WriteLine( "Package Name: " + ResourceFile );
			LoadingResources_ = true;
			File::FiFSFile file( ResourceFile + ".json" );
			file.Open( File::FsMode::Read );

			std::string fileData = file.ReadAll();
			file.Close();
			Json::Value root;
			Json::Reader rdr;

			rdr.parse( fileData, root );

			CurrentPackage_ = root[ "name" ].asCString();

			Json::Value items = root[ "resources" ];

			unsigned int uCount = items.size();
			for ( unsigned int Idx = 0; Idx < uCount; ++Idx )
			{
				CreateObject( items[ Idx ], nullptr );
			}

			LoadingResources_ = false;
		}

		Resource* ObjectRegister::GetResource( std::string ResourceName )
		{
			int Idx1 = ResourceName.find_first_of( ':' );


			std::string package = ResourceName.substr( 0, Idx1 );
			std::string resource = ResourceName.substr( Idx1 + 1 );
			std::string val;
			int Idx2 = resource.find_first_of( ':' );
			if ( Idx2 != std::string::npos )
			{
				val = resource.substr( Idx2 + 1 );
				resource = resource.substr( 0, Idx2 );
				Data::ResourceList* list = dynamic_cast<Data::ResourceList*>( Resources_[ package ][ resource ].Value() );
				if ( list == nullptr )
				{
					Logs::StaticLog::Instance()->WriteLine("Cannot load list item " + ResourceName);
					return nullptr;
				}
				if ( IsNumber( val ) )
				{
					int itemNumber = atoi(val.c_str());
					return list->GetItem( itemNumber );
				}
				else if ( val[ 0 ] == '?' )
				{
					int u = rand() % list->Size();
					return list->GetItem( u );
				}
				else
				{
					return list->GetItem( val );
				}
			}

			return Resources_[ package ][ resource ];
			
		}

		bool ObjectRegister::IsNumber( const std::string& s )
		{
			return !s.empty() && std::find_if( s.begin(),
				s.end(), [ ]( char c ) { return !std::isdigit( c ); } ) == s.end();
		}

	}
}