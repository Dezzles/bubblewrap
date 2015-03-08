#ifndef OBJECTREGISTER_H
#define OBJECTREGISTER_H

#include "Bubblewrap/Base/EvtMessage.hpp"
#include "Bubblewrap/Base/GoBase.hpp"
#include "Bubblewrap/Base/DType.hpp"
#include <vector>
#include <functional>
#include "json/json.h"
namespace Bubblewrap
{
	namespace Base
	{
		class ObjectRegister
		{
		public:
			ObjectRegister();
			~ObjectRegister();
			GoBase* GetObject( int Id );

			void Update( float Dt );
			void CheckCollisions();

			void DestroyPhase();

			void AddReceiver( std::function< void( EvtMessage ) > Function );
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


			GoBase* CreateObject( std::string Type );
			GoBase* CreateObject( Json::Value Json );
			void RegisterCreator( std::string Class, std::function < GoBase*( ) > Creator, std::function < GoBase*( Json::Value ) > CreatorJson );
			void RepeatMessage( EvtMessage Message );
		private:

			int NextId_ = 0;
			std::vector< GoBase* > Objects_;

			std::map< GoBase*, std::map< GoBase*, DBool > > CollisionMap;

			std::vector< std::function< void( EvtMessage ) > > CallBacks_;
			std::map<std::string, std::function < GoBase*( ) > > ClassGenerators_;
			std::map<std::string, std::function < GoBase*( Json::Value ) > > ClassGeneratorsJson_;
			int RegisterObject( GoBase* Object );
		};
	}
}
#endif