#include "Bubblewrap/Base/GoEntity.hpp"
#include "Bubblewrap/Base/GoComponent.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"
namespace Bubblewrap
{
	namespace Base
	{

		GoEntity::GoEntity()
		{

		}

		void GoEntity::Initialise( Json::Value Params )
		{
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
					Components_.push_back( static_cast< GoComponent* >( GetRegister().CreateObject( Params[ "components" ][ Idx ], this ) ) );
				}
			}
		}

		void GoEntity::Update( float Dt )
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

		void GoEntity::Copy( GoEntity* Target, GoEntity* Base )
		{

		}
		Math::Vector2f GoEntity::WorldPosition()
		{
			if ( GetParentEntity() == nullptr )
			{
				return LocalPosition();
			}
			return ( GetParentEntity() )->WorldPosition() + LocalPosition();
		}
		Math::Vector2f GoEntity::LocalPosition()
		{
			return Position_;
		}

		void GoEntity::SetLocalPosition( Math::Vector2f Position )
		{
			Position_ = Position;
		}
	}
}
