#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/File/File.hpp"
#include "Bubblewrap/Logs/Log.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Base/Resource.hpp"
#include "Bubblewrap/Data/ResourceList.hpp"
#include "Bubblewrap/Base/Assert.hpp"
#include "Bubblewrap/Base/Component.hpp"
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
					else
					{
						for ( auto iter = ParentlessItems_.begin(); iter != ParentlessItems_.end(); )
						{
							if ( ( *iter ) == Objects_[ Idx ] )
							{
								iter = ParentlessItems_.erase( iter );
							}
							else
								++iter;
						}
					}
					destroyObject = true;
				}
			}
			if ( !destroyObject )
				return;

			for ( std::vector<GoBase*>::iterator iter = ToAttach_.begin(); iter != ToAttach_.end(); )
			{
				if ( ( *iter )->Destroy_ )
				{
					iter = ToAttach_.erase( iter );
				}
				else
				{
					++iter;
				}
			}
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

		void ObjectRegister::RegisterCreator( std::string Class, std::function < GoBase*( ) > Creator, std::function< void( GoBase*, GoBase* ) > Copier, bool Override )
		{
			Logs::Log log( "ObjectRegister::RegisterCreator" );
			log.WriteLine( "Registering class: " + Class, Logs::StaticLog::INFO );
			if ( ( ClassGenerators_.find( Class ) != ClassGenerators_.end() ) && !Override )
			{
				log.WriteLine( "Overriding class: " + Class, Logs::StaticLog::INFO );
			}
			ClassGenerators_[ Class ].ClassGenerator_ = Creator;
			ClassGenerators_[ Class ].ClassCopier_ = Copier;
		}

		GoBase* ObjectRegister::CreateObject( char* Type, Entity* Parent )
		{
			return CreateObject( std::string( Type ), Parent );
		}

		GoBase* ObjectRegister::CreateObject( std::string Type, Entity* Parent )
		{
			Logs::Log log( "ObjectRegister::CreateObject" );
			log.WriteLine( "CreateObject: " + Type + " (TYPE)", Logs::StaticLog::VERBOSE );
			IncLoad();

			GoBase* obj = ClassGenerators_[ Type ].ClassGenerator_();
			obj->Parent_ = Parent;
			RegisterObject( obj );
			if ( !( LoadingPackage_ || LoadingResources_ ))
			{
				log.WriteLine( "Sending to Attach", Logs::StaticLog::VERBOSE );
				char buffer[ 256 ];
				sprintf( buffer, "Id: %d", obj->Id() );
				log.WriteLine( buffer, Logs::StaticLog::VERBOSE );
				ToAttach_.push_back( obj );
			}
			if ( Parent == nullptr )
			{
				ParentlessItems_.push_back( obj );
			}
			else
			{
				Component* componentObject = dynamic_cast<Component*>( obj );
				if ( componentObject != nullptr )
					Parent->Components_.push_back( componentObject );
				else
				{
					Entity* entityObject = dynamic_cast<Entity*> ( obj );
					if ( entityObject != nullptr )
						Parent->Children_.push_back( entityObject );
				}
			}
			DecLoad();

			return obj;
		}

		GoBase* ObjectRegister::CreateObject( Json::Value Json, Entity* Parent )
		{
			IncLoad();
			Logs::Log log( "ObjectRegister::CreateObject" );
			log.WriteLine( "CreateObject: " + Json[ "type" ].asString() + " (JSON)", Logs::StaticLog::VERBOSE );
			
			std::string Type = Json[ "type" ].asString();

			AssertMessage( ClassGenerators_.find(Type) != ClassGenerators_.end(), "Type not found: " + Type)
			GoBase* obj = ClassGenerators_[ Type ].ClassGenerator_( );
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
			else
			{
				Component* componentObject = dynamic_cast<Component*>( obj );
				if ( componentObject != nullptr )
					Parent->Components_.push_back( componentObject );
			}
			obj->Initialise( Json );
			if ( LoadingPackage_ && ( Parent == nullptr ) )
			{
				PackageObjects_[ CurrentPackage_ ][ obj->GetName() ] = obj;
			}
			else if ( LoadingResources_ && ( Parent == nullptr ) )
			{
				Resource* resourceObj = dynamic_cast<Resource*>( obj );
				AssertMessage ( resourceObj != nullptr, "Loaded object is not a Resource" );
				Resources_[ CurrentPackage_ ][ obj->GetName() ] = resourceObj;
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
			if ( LoadingPackage_ || LoadingResources_)
			{
				assert( false );
			}
			unsigned int uCount = ToAttach_.size();
			if ( uCount == 0 )
				return;
			Logs::Log log( "ObjectRegister::AttachItems" );
			log.WriteLine( "Calling attach", Logs::StaticLog::VERBOSE );
			std::vector< GoBase* > toDo = ToAttach_;
			ToAttach_.clear();
			for ( unsigned int Idx = 0; Idx < uCount; ++Idx )
			{
				try
				{
					toDo[ Idx ]->OnAttach();
				}
				catch (...)
				{

				}
			}
		}

		void ObjectRegister::LoadPackage( std::string PackageFile )
		{
			Logs::Log log( "ObjectRegiser::LoadPackage (" + PackageFile + ")" );
			log.WriteLine( "Package Name: " + PackageFile, Logs::StaticLog::VERBOSE );
			LoadingPackage_ = true;
			File::File file = GetManager()->GetFileManager().GetFile( PackageFile );
			file.Open( File::FileMode::Read );

			char* data = file.ReadAll();
			std::string fileData = data;
			delete data;
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
					log.WriteLine( ParentlessItems_[ Idx ]->GetName() + "{" + ParentlessItems_[ Idx ]->TypeName() + "}", Logs::StaticLog::VERBOSE );
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
			}
		}

		Managers::Managers* ObjectRegister::GetManager()
		{
			return Managers_;
		}

		void ObjectRegister::LoadResources( std::string ResourceFile )
		{
			Logs::Log log( "ObjectRegiser::LoadResources (" + ResourceFile + ")" );
			log.WriteLine( "Package Name: " + ResourceFile, Logs::StaticLog::VERBOSE );
			LoadingResources_ = true;
			File::File file = GetManager()->GetFileManager().GetFile( ResourceFile + ".json" ) ;
			file.Open( File::FileMode::Read );

			char* data = file.ReadAll();
			std::string fileData = data;
			delete data;
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
					Logs::StaticLog::Instance()->WriteLine("Cannot load list item " + ResourceName, Logs::StaticLog::ERROR );
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