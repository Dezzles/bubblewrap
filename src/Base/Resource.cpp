#include "Bubblewrap/Base/Resource.hpp"

namespace Bubblewrap
{
	namespace Base
	{
		Resource::Resource()
		{

		}

		void Resource::Initialise( Json::Value Params )
		{
			GoBase::Initialise( Params );
		}

		void Resource::Copy( Resource* Target, Resource* Base )
		{
			AssertMessage( false, "Copy should not be called on Resources" );

		}
	}
}