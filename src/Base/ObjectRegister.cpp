#include "Bubblewrap/Base/ObjectRegister.hpp"
//#include "CollisionSystem.h"
#include "Bubblewrap/Base/GoEntity.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		ObjectRegister::ObjectRegister()
		{
			REGISTER_CLASS( this, GoEntity );
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
			Objects_.push_back( Object );

			Object->OnAttach();

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
			for ( unsigned int Idx = 0; Idx < Objects_.size(); ++Idx )
			{
				Objects_[ Idx ]->Update( Dt );
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

		void ObjectRegister::RegisterCreator( std::string Class, std::function < GoBase*( ) > Creator, std::function < GoBase*( Json::Value ) > CreatorJson )
		{
			ClassGenerators_[ Class ] = Creator;
			ClassGeneratorsJson_[ Class ] = CreatorJson;
		}

		GoBase* ObjectRegister::CreateObject( std::string Type )
		{
			GoBase* obj = ClassGenerators_[ Type ]();

			RegisterObject( obj );

			return obj;
		}

		GoBase* ObjectRegister::CreateObject( Json::Value Json )
		{
			std::string Type = Json[ "type" ].asString();
			GoBase* obj = ClassGeneratorsJson_[ Type ]( Json );

			RegisterObject( obj );

			return obj;

		}
	}
}