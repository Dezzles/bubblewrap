#ifndef BUBBLEWRAP_RESOURCE_HPP
#define BUBBLEWRAP_RESOURCE_HPP

#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/Defines.hpp"

namespace Bubblewrap
{
	namespace Base
	{
		class Resource
			: public GoBase
		{
		public:
			Resource();
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Resource );

			virtual void Update( float Dt );


		};
	}
}



#endif