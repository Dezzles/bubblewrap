#ifndef BUBBLEWRAP_DATA_STRINGLIST_HPP
#define BUBBLEWRAP_DATA_STRINGLIST_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Resource.hpp"

#include <vector>

namespace Bubblewrap
{
	namespace Data
	{
		/*! The Stringlist class is designed to store a list of strings.
		Strings in a string list can be retrieved by text in the following manners:
		- "resourceFile:listName:item_number"
		- "resourceFile:listName:?"

		The question mark indicates that a random item in the resource list should be returned.

		StringList can have the following JSON parameters:
		- name \a Required - The name of the string list
		- items \a Required - A Json list of strings to be included in the list
		*/
		class StringList
			: public Base::Resource
		{
		public:
			/*! Creates an instance of StringList */
			StringList();

			/*! Initialises a StringList object
			\param Params A Json value containing the data to initialise the ResourceList object with
			*/
			void Initialise( Json::Value Params );

			CREATE_REGISTER( StringList );
			
			/*! Returns the number of items in the list */
			unsigned int Size();
			/*! Gets a string from the string list by index
			\param Idx The index to be retrieved
			\returns The item at index Idx, or an empty string if the value is outside range.
			*/
			std::string GetItem( unsigned int Idx );

			/*! Gets a string from the string list by index
			\param Idx The index to be retrieved
			\returns The item at index Idx, or an empty string if the value is outside range.
			*/
			std::string operator[]( unsigned int Idx );
		protected:
			/*! A vector containing a list of all strings stored in the list */
			std::vector<std::string> Items_;
			/*! A cached copy of Items_.size()*/
			unsigned int Size_;
		};
	}
}





#endif