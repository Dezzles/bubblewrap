#ifndef OBJECTREGISTER_H
#define OBJECTREGISTER_H

#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/DType.hpp"
#include <vector>
#include <functional>
#include "json/json.h"
namespace Bubblewrap
{
	namespace Game
	{
		class Game;

	}
	namespace Managers
	{
		class Managers;
	}
	namespace Base
	{
		class Resource;
		class ObjectRegister
		{
			friend Game::Game;
		public:
			/*! Creates an object register
			*/
			ObjectRegister();
			/*! Destroys an object register as well as all components, resources and entities attached to it
			*/
			~ObjectRegister();

			/*! Returns an object by id.
				\param Id The id to be searched for
				\return If an object with with id Id is not found, returns nullptr. Otherwise, the object.
			*/
			GoBase* GetObject( int Id );

			/*! Updates all objects that have not been assigned parents.
				\param Dt The timestep, in seconds, since the last update.
			*/
			void Update( float Dt );

			/*! Processes the destruction of all objects that have had Destroy() called on them during this update step.
			*/
			void DestroyPhase();

			/*! Gets all objects instantiated of type T_
				\param
			*/
			template<typename T_>
			std::vector<T_*> GetObjectsByType()
			{
				std::vector<T_*> ret;
				for ( unsigned int Idx = 0; Idx < Objects_.size(); ++Idx )
				{
					T_* test = dynamic_cast< T_* >( Objects_[ Idx ] );
					if ( test != nullptr )
					{
						ret.push_back( test );
					}
				}
				return ret;

			}

			/*! Creates a new object by type name and attaches it to a parent.
				\param Type The type name of the object to be created.
				\param Parent The parent this object should be attached to. If Parent is nullptr the created object becomes a root object.
				\return A pointer to the newly created object
			*/
			GoBase* CreateObject( std::string Type, Entity* Parent );
			/*! Creates a new object using data in a Json array and attaches it to a parent.
				\param Json The Json data that defines the object to be created.
				\param Parent The parent this object should be attached to. If Parent is nullptr the created object becomes a root object.
				\return A pointer to the newly created object
			*/
			GoBase* CreateObject( Json::Value Json, Entity* Parent );
			 
			/*!	Registers creator functions for an object. Note that the functions can easily be attached to a class by using the
				CREATE_REGISTER and CREATE_REGISTER_OVERRIDE functions in Defines.hpp. Override is used to dictate when functionless
				version of a class (such as Texture, Music, Sound etc.) should be ignored and implemented versions should be used instead.
				\param Class The name of the class to be created. This doesn't necessarily need to match the class's name.
				\param Creator A function that will create an instance of the object
				\param Copier A function that will copy data from one instance of the class to another
				\param Override Dictates whether these creators should override creators already written for this class.
			*/
			void RegisterCreator( std::string Class, std::function < GoBase*( ) > Creator, std::function< void( GoBase*, GoBase* ) > Copier, 
				bool Override = false );

			/*! Sets the Manager for the Object Register that will be added to all objects when they are created. This can only be called once and
				should only be called by Game.
			*/
			void SetManager( Managers::Managers* Manager );

			/*! Gets the manager that has been added to this object register
				\return A pointer to the Managers for this object register
			*/
			Managers::Managers* GetManager();

			/*! Loads a package file into the object register
				\param PackageFile The name of the file containing the package data
			*/
			void LoadPackage( std::string PackageFile );

			/*! Creates an object based on an object loaded from a package.
			\param Package The name of the package the object is stored in
			\param Name The name of the object in the package
			\param Parent The object that the new object should be attached to
			\return A pointer to the newly created object
			*/
			GoBase* LoadObject( std::string Package, std::string Name, Entity* Parent );
			/*! Creates an object based on an object loaded from a package.
			\param Name The package and name of the object, in the format "Package:ObjectName"
			\param Parent The object that the new object should be attached to
			\return A pointer to the newly created object
			*/
			GoBase* LoadObject( std::string Name, Entity* Parent );

			/*! Creates a copy of an object 
				\param Obj The object to be copied
				\param Parent The object that the copy should be attached to
				\return A pointer to the newly created object
			*/
			GoBase* CreateCopy( GoBase* Obj, Entity* Parent );

			/*! Prints out the current hierarchy of objects in the object register, its children and its components.
			*/
			void LogHierarchy();


			/*! Loads a set of resources from a file
				\param ResourceFile The name of the file that the resources are stored in
			*/
			void LoadResources( std::string ResourceFile );

			/*! Loads a specific resource
				\param ResourceName The name of the resource to be loaded in the format "ResourceSet:ResourceName"
				\return The loaded resource. If no such resource exists, nullptr will be returned.
			*/
			Resource* GetResource( std::string ResourceName );
		private:
			struct OrGenerators
			{
				std::function < GoBase*( ) > ClassGenerator_;
				std::function < void( GoBase*, GoBase* ) > ClassCopier_;
			};
			int NextId_ = 0;
			std::vector< GoBase* > Objects_;

			std::map< GoBase*, std::map< GoBase*, DBool > > CollisionMap;

			// std::vector< std::function< void( EvtMessage ) > > CallBacks_;
			std::map<std::string, OrGenerators > ClassGenerators_;
			int RegisterObject( GoBase* Object );

			std::map<std::string, GoBase*> Basis_;

			std::vector< GoBase* > ParentlessItems_;
			
			Managers::Managers* Managers_ = nullptr;

			std::vector<GoBase*> ToAttach_;

			int LoadState_;

			void AttachItems();

			std::map<std::string, std::map<std::string, GoBase*>> PackageObjects_;
			std::string CurrentPackage_;
			bool LoadingPackage_;
			bool LoadingResources_;

			void IncLoad();
			void DecLoad();

			std::map<std::string, std::map<std::string, DType<Resource*, nullptr>>> Resources_;

			bool IsNumber( const std::string& s );

		};
	}
}
#endif