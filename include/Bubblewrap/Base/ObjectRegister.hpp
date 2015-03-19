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
		class ObjectRegister
		{
			friend Game::Game;
		public:
			ObjectRegister();
			~ObjectRegister();
			GoBase* GetObject( int Id );

			void Update( float Dt );
			void CheckCollisions();

			void DestroyPhase();

//			void AddReceiver( std::function< void( EvtMessage ) > Function );
			template<typename T>
			std::vector<T*> GetObjectsByType()
			{
				std::vector<T*> ret;
				for ( unsigned int Idx = 0; Idx < Objects_.size(); ++Idx )
				{
					T* test = dynamic_cast< T* >( Objects_[ Idx ] );
					if ( test != nullptr )
					{
						ret.push_back( test );
					}
				}
				return ret;

			}


			GoBase* CreateObject( std::string Type, Entity* Parent );
			GoBase* CreateObject( Json::Value Json, Entity* Parent );
			void RegisterCreator( std::string Class, std::function < GoBase*( ) > Creator, std::function < GoBase*( Json::Value ) > CreatorJson,
								  std::function< void( GoBase*, GoBase* ) > Copier );
			// void RepeatMessage( EvtMessage Message );
			void SetManager( Managers::Managers* Manager );

			void LoadPackage( std::string PackageFile );
			GoBase* LoadObject( std::string Package_, std::string Name, Entity* Parent );
			GoBase* LoadObject( std::string Name, Entity* Parent );

			GoBase* CreateCopy( GoBase* Obj, Entity* Parent );

			void LogHierarchy();
		private:
			struct OrGenerators
			{
				std::function < GoBase*( ) > ClassGenerator_;
				std::function < GoBase*( Json::Value ) > ClassGeneratorJson_;
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

			void IncLoad();
			void DecLoad();
		};
	}
}
#endif