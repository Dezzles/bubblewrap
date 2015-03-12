#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Component.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"
namespace Bubblewrap
{
	namespace Base
	{

		Entity::Entity()
		{

		}

		void Entity::Initialise( Json::Value Params )
		{
			GoBase::Initialise( Params );
			Name_ = Params[ "name" ].asString();
			if ( Params[ "position" ].isObject() )
			{
				float x = Params[ "position" ][ "x" ].asFloat();
				float y = Params[ "position" ][ "y" ].asFloat();

				Position_ = Math::Vector2f( x, y );
			}
			if ( Params[ "children" ].isArray() )
			{
				for ( unsigned int Idx = 0; Idx < Params[ "children" ].size(); ++Idx )
				{
					Children_.push_back( GetRegister().CreateObject( Params[ "children" ][ Idx ], this ) );
				}
			}
			if ( Params[ "components" ].isArray() )
			{
				for ( unsigned int Idx = 0; Idx < Params[ "components" ].size(); ++Idx )
				{
					Components_.push_back( static_cast< Component* >( GetRegister().CreateObject( Params[ "components" ][ Idx ], this ) ) );
				}
			}
		}

		void Entity::Update( float Dt )
		{
			unsigned int uCount = Components_.size();
			for ( unsigned int Idx = 0; Idx < uCount; ++Idx )
			{
				Components_[ Idx ]->Update( Dt );
			}

			uCount = Children_.size();
			for ( unsigned int Idx = 0; Idx < uCount; ++Idx )
			{
				Children_[ Idx ]->Update( Dt );
			}
		}

		void Entity::Copy( Entity* Target, Entity* Base )
		{
			Target->Position_ = Target->Position_;
			unsigned int uCount = Base->Components_.size();
			for ( unsigned int Idx = 0; Idx < uCount; ++Idx )
			{
				Target->Components_.push_back( static_cast<Component*>( Base->GetRegister().CreateCopy( Base->Components_[ Idx ], Target ) ) );
			}

			uCount = Base->Children_.size();
			for ( unsigned int Idx = 0; Idx < uCount; ++Idx )
			{
				Target->Children_.push_back( Base->GetRegister().CreateCopy( Base->Children_[ Idx ], Target ) );
				// Children_[ Idx ]->Update( Dt );
			}

		}
		Math::Vector2f Entity::WorldPosition()
		{
			if ( GetParentEntity() == nullptr )
			{
				return LocalPosition();
			}
			return ( GetParentEntity() )->WorldPosition() + LocalPosition();
		}
		Math::Vector2f Entity::LocalPosition()
		{
			return Position_;
		}

		void Entity::SetLocalPosition( Math::Vector2f Position )
		{
			Position_ = Position;
		}
	}
}
