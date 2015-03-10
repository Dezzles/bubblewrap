#ifndef GOENTITY_H
#define GOENTITY_H

#include "Bubblewrap/Base/GoBase.hpp"
#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Math/MaVector.hpp"
#include "Json/Json.h"



namespace Bubblewrap
{
	namespace Base
	{

		EMPTY_POINTER( GoEntity );
		class GoComponent;
		class GoEntity
			: public GoBase
		{
			GoEntity();
			void Initialise( Json::Value Params );

			std::vector < GoBase* > Children_;
			std::vector< GoComponent* > Components_;

			Math::Vector2f Position_;

			std::string Name_;
		public:
			CREATE_REGISTER( GoEntity );

			virtual void Update( float Dt );

			template <class T>
			std::vector<T*> GetComponentsByType()
			{
				std::vector<T*> ret;
				unsigned int cCount = Components_.size();
				for ( unsigned int Idx = 0; Idx < cCount; ++Idx )
				{
					T* test = dynamic_cast< T* >( Components_[ Idx ] );
					if ( test != nullptr )
					{
						ret.push_back( test );
					}
				}
				return ret;
			}

			template <class T>
			std::vector<T*> GetComponentsByType( std::string Name )
			{
				std::vector<T*> ret;
				unsigned int cCount = Components_.size();
				for ( unsigned int Idx = 0; Idx < cCount; ++Idx )
				{
					T* test = dynamic_cast< T* >( Components_[ Idx ] );
					if ( ( test != nullptr ) && ( test->GetName() == Name ) )
					{
						ret.push_back( test );
					}
				}
				return ret;
			}


			void SetLocalPosition( Math::Vector2f Position );
			Math::Vector2f WorldPosition();
			Math::Vector2f LocalPosition();
		};
	}
}

#endif