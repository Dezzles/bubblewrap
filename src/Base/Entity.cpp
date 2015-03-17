#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Component.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Logs/Log.hpp"
namespace Bubblewrap
{
	namespace Base
	{

		Entity::Entity()
		{

		}

		void Entity::Initialise( Json::Value Params )
		{
			Logs::Log log( "Entity::Initialise" + Params[ "name"].asString() );

			GoBase::Initialise( Params );
			if ( Params[ "position" ].isObject() )
			{
				float x = Params[ "position" ][ "x" ].asFloat();
				float y = Params[ "position" ][ "y" ].asFloat();

				Position_ = Math::Vector2f( x, y );
			}
			if ( Params[ "children" ].isArray() )
			{
				log.WriteLine( "Loading children" );
				for ( unsigned int Idx = 0; Idx < Params[ "children" ].size(); ++Idx )
				{
					Children_.push_back( GetRegister().CreateObject( Params[ "children" ][ Idx ], this ) );
				}
				log.WriteLine( "Loaded children" );
			}
			if ( Params[ "components" ].isArray() )
			{
				log.WriteLine( "Loading components" );
				for ( unsigned int Idx = 0; Idx < Params[ "components" ].size(); ++Idx )
				{
					Components_.push_back( static_cast< Component* >( GetRegister().CreateObject( Params[ "components" ][ Idx ], this ) ) );
				}
				log.WriteLine( "Loaded components" );
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
			GoBase::Copy( Target, Base );
			Logs::Log log( "Entity::Copy" );
			Target->Position_ = Base->Position_;
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

		void Entity::LogHierarchy()
		{
			Logs::Log log;
			log.WriteLine( GetName() + "{Entity}" );
			{
				Logs::Log log2;

				for ( unsigned int Idx = 0; Idx < Components_.size(); ++Idx )
				{
					/*try
					{
						log2.WriteLine( Components_[ Idx ]->GetName() + "{" + Components_[ Idx ]->TypeName() + "}" );
					}
					catch (int)
					{
					}/**/
				}
				for ( unsigned int Idx = 0; Idx < Children_.size(); ++Idx )
					( ( Entity* ) Children_[ Idx ] )->LogHierarchy();
			}
		}
	}
}
