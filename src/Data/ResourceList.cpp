#include "Bubblewrap/Data/ResourceList.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"
namespace Bubblewrap
{
	namespace Data
	{
		ResourceList::ResourceList()
		{

		}

		void ResourceList::Initialise( Json::Value Params )
		{
			Resource::Initialise( Params );
			Json::Value list = Params[ "items" ];
			for ( unsigned int Idx = 0; Idx < list.size(); ++Idx )
			{
				GoBase* newObject = GetRegister().CreateObject( list[Idx ], nullptr);
				
				Items_.push_back( dynamic_cast<Base::Resource*>( newObject ) ); 
			}
			Size_ = list.size();
		}

		void ResourceList::Copy( ResourceList* Target, ResourceList* Base )
		{
			Resource::Copy( Target, Base );
			Target->Items_ = Base->Items_;
			Target->Size_ = Base->Size_;
		}

		unsigned int ResourceList::Size()
		{
			return Size_;
		}

		Base::Resource* ResourceList::GetItem( unsigned int Idx )
		{
			if ( Idx < Size() )
				return Items_[ Idx ];
			return nullptr;
		}

		Base::Resource* ResourceList::operator[]( unsigned int Idx )
		{
			if ( Idx < Size() )
				return Items_[ Idx ];
			return nullptr;
		}

		Base::Resource* ResourceList::GetItem( std::string Name )
		{
			for ( unsigned int Idx = 0; Idx < Size_; ++Idx )
			{
				if ( Items_[ Idx ]->GetName() == Name )
				{
					return Items_[ Idx ];
				}
			}
			return nullptr;
		}

	}
}