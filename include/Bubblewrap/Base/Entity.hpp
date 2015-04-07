#ifndef Entity_H
#define Entity_H

#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Math/Vector3.hpp"
#include "Json/Json.h"



namespace Bubblewrap
{
	namespace Events
	{
		class EventManager;
	}
	namespace Base
	{

		EMPTY_POINTER( Entity );
		class Component;
		class ObjectRegister;
		/*! The Entity class that most components should be created attached to. 
			The Entity class dictates the base position of all child entities and components.
			Unlike most components, it is acceptable for an Entity to be created without a parent entity.
			An entity can have the following JSON parameters:
			- position - a plain text description of a Vector3 (e.g. "0 0.5 1.0")
			- children - a json array of entities
			- components - a json array of components

		*/
		class Entity
			: public GoBase
		{
			friend ObjectRegister;
			friend Events::EventManager;

			//! Creates the Entity with default values
			Entity();

			std::vector < GoBase* > Children_;
			std::vector< Component* > Components_;

			Math::Vector3f Position_;
			void RemoveChild( GoBase* Object );
		public:
			/*! Initialises an entity
			\param Params A Json value containing the data to initialise the entity with
			*/
			void Initialise( Json::Value Params );

			/*! Destroys an entity, its child entities and all attached components at the end of the current update step.
			*/
			virtual void Destroy();
			CREATE_REGISTER( Entity );

			/*! Updates the entity based on the current timestep.
				Updates will occur in the following order:
				-# Components attached to the entity
				-# Entities that are children of this entity

				\param Dt The current timestep in seconds.
			*/
			virtual void Update( float Dt );

			/*! Gets a list of all components attached directly to this Entity of type T_.
				\tparam T_ The type of the component being searched for
				\return A vector of components that match the given type.
			*/
			template <class T_>
			std::vector<T_*> GetComponentsByType()
			{
				std::vector<T_*> ret;
				unsigned int cCount = Components_.size();
				for ( unsigned int Idx = 0; Idx < cCount; ++Idx )
				{
					T_* test = dynamic_cast< T_* >( Components_[ Idx ] );
					if ( test != nullptr )
					{
						ret.push_back( test );
					}
				}
				return ret;
			}

			/*! Gets a list of all components attached directly to this Entity of type T_ with name Name
				\param Name The name assigned to the compoonent that is being searched for
				\tparam T_ The type of component being searched for
				\return A list of components that match both the type and name
			*/
			template <class T_>
			std::vector<T_*> GetComponentsByType( std::string Name )
			{
				std::vector<T_*> ret;
				unsigned int cCount = Components_.size();
				for ( unsigned int Idx = 0; Idx < cCount; ++Idx )
				{
					T_* test = dynamic_cast< T_* >( Components_[ Idx ] );
					if ( ( test != nullptr ) && ( test->GetName() == Name ) )
					{
						ret.push_back( test );
					}
				}
				return ret;
			}

			/*! Gets a list of all components attached to this Entity, or and of its children, of type T_.
				\tparam T_ The type of the component being searched for
				\return A vector of components that match the given type.
			*/
			template <class T_>
			std::vector<T_*> GetComponentsByTypeAnyChild()
			{
				std::vector<T_*> ret;
				unsigned int cCount = Components_.size();
				for ( unsigned int Idx = 0; Idx < cCount; ++Idx )
				{
					T_* test = dynamic_cast< T_* >( Components_[ Idx ] );
					if ( test != nullptr )
					{
						ret.push_back( test );
					}
				}
				cCount = Children_.size();
				for ( unsigned int Idx = 0; Idx < cCount; ++Idx )
				{
					auto result = ( ( Entity* ) Children_[ Idx ] )->GetComponentsByTypeAnyChild<T_>();
					for ( unsigned int Idx = 0; Idx < result.size(); ++Idx )
					{
						ret.push_back( result[ Idx ] );
					}
				}
				return ret;
			}

			/*! Sets the local position of the Entity
				\param Position The position that the Entity should be set at
			*/
			void SetLocalPosition( Math::Vector3f Position );

			/*! Returns the Entity's position in world coordinates.
				This position will be modified based on an Entity's parent's coordinates
				\return Entity's position in world coordinates
			*/
			Math::Vector3f WorldPosition();

			/*! Returns the Entity's position in local coordinates
			\return Entity's position in local coordinates
			*/
			Math::Vector3f LocalPosition();

			/*! Gets the root entity that this object is attached to.
				\return Entity's root parent. Returns nullptr if this is the root entity.
			*/
			Entity* GetRootEntity();

			/*! Prints out the current hierarchy of this entity, its children and its components.
			*/
			void LogHierarchy();

		};
	}
}

#endif