#ifndef BUBBLEWRAP_DATA_RESOURCELIST_HPP
#define BUBBLEWRAP_DATA_RESOURCELIST_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Resource.hpp"

#include <vector>

namespace Bubblewrap
{
	namespace Data
	{
		/*! The ResourceList class is designed to store a list of Resources.
			Resources stored in ResourceList don't necessarily need to be of the same type.
			Items in a resource list can be retrieved by text in the following manners:
			- "resourceFile:listName:item_name"
			- "resourceFile:listName:item_number"
			- "resourceFile:listName:?"

			In the above examples, item_name can not be convertible to a number, or a '?'. The question mark
			indicates that a random item in the resource list should be returned.
			
			ResourceList can have the following JSON parameters:
			- name \a Required - The name of the resource list
			- resources \a Required - A Json list of resources to be included in the list
		*/
		class ResourceList
			: public Base::Resource
		{
		public:
			/*! Creates an instance of ResourceList */
			ResourceList();


			/*! Initialises a ResourceList object
			\param Params A Json value containing the data to initialise the ResourceList object with
			*/
			void Initialise( Json::Value Params );

			CREATE_REGISTER( ResourceList );
			
			/*! Returns the number of items in the list */
			unsigned int Size();

			/*! Gets an item from the resource list by index
				\param Idx The index to be retrieved
				\returns The item at index Idx, or nullptr if the value is outside range.
			*/
			Base::Resource* GetItem( unsigned int Idx );
			/*! Gets an item from the resource list by index
			\param Idx The index to be retrieved
			\returns The item at index Idx, or nullptr if the value is outside range.
			*/
			Base::Resource* operator[]( unsigned int Idx );

			/*! Gets an item from the resource list by name
			\param Name the name of the object being searched for
			\returns The item named Name, or nullptr if no object in the list has the name Name.
			*/
			Base::Resource* GetItem( std::string Name );
		protected:
			/*! A vector containing a list of all items stored in the list */
			std::vector<Base::Resource*> Items_;
			/*! A cached copy of Items_.size()*/
			unsigned int Size_;
		};
	}
}





#endif