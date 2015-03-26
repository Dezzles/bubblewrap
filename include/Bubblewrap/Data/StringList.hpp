#ifndef BUBBLEWRAP_STRINGLIST_HPP
#define BUBBLEWRAP_STRINGLIST_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Resource.hpp"

#include <vector>

namespace Bubblewrap
{
	namespace Data
	{
		class StringList
			: public Base::Resource
		{
		public:
			StringList();
			void Initialise( Json::Value Params );

			CREATE_REGISTER( StringList );
			
			unsigned int Size();
			std::string GetItem( unsigned int Idx );
			std::string operator[](unsigned int Idx);
		protected:
			std::vector<std::string> Items_;
			unsigned int Size_;
		};
	}
}





#endif