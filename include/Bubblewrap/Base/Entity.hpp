#ifndef Entity_H
#define Entity_H

#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
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
		class Entity
			: public GoBase
		{
			friend Events::EventManager;
			Entity();
			void Initialise( Json::Value Params );

			std::vector < GoBase* > Children_;
			std::vector< Component* > Components_;

			Math::Vector2f Position_;

		public:
			CREATE_REGISTER( Entity );

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

			template <class T>
			std::vector<T*> GetComponentsByTypeAnyChild( )
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
				cCount = Children_.size();
				for ( unsigned int Idx = 0; Idx < cCount; ++Idx )
				{
					auto result = ( ( Entity* ) Children_[ Idx ] )->GetComponentsByTypeAnyChild<T>();
					for ( unsigned int Idx = 0; Idx < result.size(); ++Idx )
					{
						ret.push_back( result[ Idx ] );
					}
				}
				return ret;
			}


			void SetLocalPosition( Math::Vector2f Position );
			Math::Vector2f WorldPosition();
			Math::Vector2f LocalPosition();
			Entity* GetRootEntity();
			void LogHierarchy();
		};
	}
}

#endif