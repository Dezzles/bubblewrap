#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Render/Sprite.hpp"
#include "Bubblewrap/Render/Texture.hpp"
#include "Bubblewrap/Render/Vertices.hpp"
#include "Bubblewrap/File/FSFile.hpp"
#include "Bubblewrap/Logs/Log.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		ObjectRegister::ObjectRegister()
		{
			LoadState_ = 0;
			LoadingPackage_ = false;
		}

		void ObjectRegister::RegisterClasses()
		{
			RegisterCreator( "Entity", &Entity::Create, &Entity::CreateJson, &Entity::CopyDef );
			RegisterCreator( "Sprite", &Render::Sprite::Create, &Render::Sprite::CreateJson, &Render::Sprite::CopyDef );
			RegisterCreator( "Texture", &Render::Texture::Create, &Render::Texture::CreateJson, &Render::Texture::CopyDef );
			RegisterCreator( "Vertices", &Render::Vertices::Create, &Render::Vertices::CreateJson, &Render::Vertices::CopyDef );

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
			DestroyPhase();
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
											  std::function< void( GoBase*, GoBase* ) > Copier )
		{
			Logs::Log log("ObjectRegister::RegisterCreator");
			log.WriteLine( "Registering class: " + Class );
			ClassGenerators_[ Class ].ClassGenerator_ = Creator;
			ClassGenerators_[ Class ].ClassGeneratorJson_ = CreatorJson;
			ClassGenerators_[ Class ].ClassCopier_ = Copier;
		}

		GoBase* ObjectRegister::CreateObject( std::string Type, Entity* Parent )
		{
			Logs::Log log("ObjectRegister::CreateObject");
			log.WriteLine( "CreateObject: " + Type + " (TYPE)");
			IncLoad();

			GoBase* obj = ClassGenerators_[ Type ].ClassGenerator_();
			obj->Parent_ = Parent;
			RegisterObject( obj );
			if ( !LoadingPackage_ )
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
			Logs::Log log("ObjectRegister::CreateObject");
			log.WriteLine( "CreateObject: " + Json["type"].asString() + " (JSON)" );
			std::string Type = Json[ "type" ].asString();
			GoBase* obj = ClassGenerators_[ Type ].ClassGeneratorJson_( Json );
			if ( !LoadingPackage_ )
				ToAttach_.push_back( obj );
			obj->Parent_ = Parent;
			RegisterObject( obj );
			if ( Parent == nullptr )
			{
				if ( LoadingPackage_ )
				{
				}
				else
				{
					ParentlessItems_.push_back( obj );
				}
			}
			obj->Initialise( Json );
			if ( LoadingPackage_ && (Parent == nullptr) )
			{
				PackageObjects_[ CurrentPackage_ ][ obj->GetName() ] = obj;
			}
			DecLoad();
			return obj;

		}

		void ObjectRegister::SetManager( Managers::Managers* Manager )
		{
			if ( Managers_ != nullptr )
			{
				assert( false &&  "DONT BE A DUMBASS" );
				return;
			}
			Managers_ = Manager;
		}

		void ObjectRegister::AttachItems()
		{
			Logs::Log log( "ObjectRegister::AttachItems" );
			log.WriteLine( "Calling attach" );
			if ( LoadingPackage_ )
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
			Logs::Log log("ObjectRegiser::LoadPackage (" + PackageFile + ")");
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
				( ( Entity* ) ParentlessItems_[ Idx ] )->LogHierarchy();
			}
		}

		void ObjectRegister::IncLoad()
		{
			++LoadState_;
		}

		void ObjectRegister::DecLoad()
		{
			--LoadState_;
			if ( ( LoadState_ == 0 ) && ( !LoadingPackage_ ) )
			{
				AttachItems();
			}
		}
	}
}