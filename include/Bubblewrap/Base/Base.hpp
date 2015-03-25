#ifndef GoBase_H
#define GoBase_H

#include "Json/Json.h"
namespace Bubblewrap
{
	namespace Managers
	{
		class Managers;
	}
	namespace Base
	{
		class ObjectRegister;
		class Entity;
		//!  Base class used for all entities, resources and components in Bubblewrap
		/*!
		GoBase is used as the Basis for all Entity, Resource and Component objects.
		All objects that derive from GoBase should be making calls to the Copy and Initialise functions
		on GoBase in the appropriate functions.
		*/

		class GoBase
		{
			friend ObjectRegister;
		public:
			//! Base constructor for the Base object. This will initialise any data that shouldn't be serialised.
			GoBase( );
			//! Copies serialised data from one Base object to another. 
			/*! 
				\param Target The object that data will be copied to
				\param Base The object that data will be copied from
			*/
			static void Copy( GoBase* Target, GoBase* Base );

			//! The Update function on GoBase is one of the few functions that must be implemented.
			/*!
				\param dt The amount of time, in seconds, that has passed
			*/
			virtual void Update( float dt ) = 0;

			//! Destroys a GoBase object.
			void Destroy();

			//! Gets the internal Id of an object. This is assigned by the object's ObjectRegister
			/*!
				\return A unique value assigned to this object
			*/
			int Id();

			//! Returns the ObjectRegister that created the object
			/*!
				\return The ObjectRegister that created the object
			*/
			ObjectRegister & GetRegister();
			
			//! Returns the Manager assigned to this object. 
			/*! 
				\return This should return the same Manager assigned to the ObjectRegister that created this object

			*/
			Managers::Managers& GetManager();

			//! Called to indicate that the object has been attached and is ready to access its parent entity.
			/*! 
				Called at the end of a Create cycle. When an entity is created, all components and child
				entities will be created before OnAttach is called
			*/
			virtual void OnAttach();

			//! Called before an object is destroyed. 
			/*! Any references created in the OnAttach step should be destroyed here.
			*/
			virtual void OnDetach();

			//! Initialises an object when loading from a package.
			/*! Initialise is called when creating an object from a Package giving the user the opportunity
				to load data from the JSON. If inheriting from GoBase, GoBase::Initialise should be called
				at the start of the derived class's Initialise step
				\param Params A Json::Value struct that contains all data for the object
			*/
			virtual void Initialise( Json::Value Params );

			//! Returns an object's parent
			/*!
				\return The object's parent. This can be null
			*/
			Entity* GetParentEntity();

			//! Returns the name assigned to this object
			/*! Gets the name assigned to an object, this will be a blank string if one has not been assigned
				\return The name of the object. This can be an empty string
			*/
			std::string GetName();

			//! Indicates that type that the object behaves as.
			/*! Gets the name that the object should be referred to in code. This will not always match
				the name of the object itself.
				\return TypeName that the object goes by
			*/
			virtual std::string TypeName() = 0;
		private:

			Entity* Parent_;
			int Id_;
			bool Destroy_;
			ObjectRegister* ObjectRegister_;
			GoBase* Basis_;

			Managers::Managers* Manager_;

			std::string Name_;
		};
	}
}

#endif