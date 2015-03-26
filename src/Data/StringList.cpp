#include "Bubblewrap/Data/StringList.hpp"

namespace Bubblewrap
{
	namespace Data
	{
		StringList::StringList()
		{

		}

		void StringList::Initialise( Json::Value Params )
		{
			Resource::Initialise( Params );
			Json::Value list = Params[ "items" ];
			for ( unsigned int Idx = 0; Idx < list.size(); ++Idx )
			{
				Items_.push_back(list[ Idx ].asString());
			}
			Size_ = list.size();
		}

		void StringList::Copy( StringList* Target, StringList* Base )
		{
			Resource::Copy( Target, Base );
			Target->Items_ = Base->Items_;
			Target->Size_ = Base->Size_;
		}

		unsigned int StringList::Size()
		{
			return Size_;
		}

		std::string StringList::GetItem( unsigned int Idx )
		{
			return Items_[ Idx ];
		}

		std::string StringList::operator[]( unsigned int Idx )
		{
			return Items_[ Idx ];
		}


	}
}