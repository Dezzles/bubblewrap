#ifndef BUBBLEWRAP_RESOURCE_HPP
#define BUBBLEWRAP_RESOURCE_HPP

#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/Defines.hpp"

namespace Bubblewrap
{
	namespace Base
	{
		/*! Objects that inherit from Resource are generally only created
			once and are stored as resources in ObjectRegister.
		*/
		class Resource
			: public GoBase
		{
		public:
			/*! Creates a Resource
			*/
			Resource();
			/*! Initialises the values in a Resource
				\param Params A Json object that contains data required to initialise the object.
			*/
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Resource );

		};
	}
}



#endif