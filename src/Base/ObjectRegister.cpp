#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Base/GoEntity.hpp"
#include "Bubblewrap/Base/GoBase.hpp"
#include "Bubblewrap/Render/ReSprite.hpp"
#include "Bubblewrap/Render/ReTexture.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		ObjectRegister::ObjectRegister()
		{
			RegisterCreator( "GoEntity", &GoEntity::Create, &GoEntity::CreateJson, &GoEntity::CopyDef );
			RegisterCreator( "ReSprite", &Render::ReSprite::Create, &Render::ReSprite::CreateJson, &Render::ReSprite::CopyDef );
			RegisterCreator( "ReTexture", &Render::ReTexture::Create, &Render::ReTexture::CreateJson, &Render::ReTexture::CopyDef );
			LoadState_ = 0;
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
					EvtMessage DestroyMessage( 0 /* TODO: Add Value*/ );
					DestroyMessage.Data_ = &Objects_[ Idx ]->Id_;
					RepeatMessage( DestroyMessage );
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

		void ObjectRegister::RepeatMessage( EvtMessage  Message )
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
		}

		void ObjectRegister::RegisterCreator( std::string Class, std::function < GoBase*( ) > Creator, std::function < GoBase*( Json::Value ) > CreatorJson, 
											  std::function< void( GoBase*, GoBase* ) > Copier )
		{
			ClassGenerators_[ Class ].ClassGenerator_ = Creator;
			ClassGenerators_[ Class ].ClassGeneratorJson_ = CreatorJson;
			ClassGenerators_[ Class ].ClassCopier_ = Copier;
		}

		GoBase* ObjectRegister::CreateObject( std::string Type, GoEntity* Parent )
		{
			++LoadState_;
			GoBase* obj = ClassGenerators_[ Type ].ClassGenerator_();
			obj->Parent_ = Parent;
			RegisterObject( obj );
			ToAttach_.push_back( obj );

			if ( Parent == nullptr )
			{
				ParentlessItems_.push_back( obj );
			}
			--LoadState_;
			if ( LoadState_ == 0 )
			{
				AttachItems();
			}

			return obj;
		}

		GoBase* ObjectRegister::CreateObject( Json::Value Json, GoEntity* Parent )
		{
			++LoadState_;
			std::string Type = Json[ "type" ].asString();
			GoBase* obj = ClassGenerators_[ Type ].ClassGeneratorJson_( Json );
			ToAttach_.push_back( obj );
			obj->Parent_ = Parent;
			RegisterObject( obj );
			if ( Parent == nullptr )
			{
				ParentlessItems_.push_back( obj );
			}
			obj->Initialise( Json );
			--LoadState_;
			if ( LoadState_ == 0 )
			{
				AttachItems();
			}
			return obj;

		}

		void ObjectRegister::SetManager( Managers::MgrManagers* Manager )
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
			unsigned int uCount = ToAttach_.size();
			for ( unsigned int Idx = 0; Idx < uCount; ++Idx )
			{
				ToAttach_[ Idx ]->OnAttach();
			}
			ToAttach_.clear();
		}
	}
}