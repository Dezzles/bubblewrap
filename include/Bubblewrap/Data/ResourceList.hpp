#ifndef BUBBLEWRAP_RESOURCELIST_HPP
#define BUBBLEWRAP_RESOURCELIST_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Resource.hpp"

#include <vector>

namespace Bubblewrap
{
	namespace Data
	{
		class ResourceList
			: public Base::Resource
		{
		public:
			ResourceList();
			void Initialise( Json::Value Params );

			CREATE_REGISTER( ResourceList );
			
			unsigned int Size();
			Base::Resource* GetItem( unsigned int Idx );
			Base::Resource* operator[]( unsigned int Idx );

			Base::Resource* GetItem( std::string Name );
		protected:
			std::vector<Base::Resource*> Items_;
			unsigned int Size_;
		};
	}
}





#endif