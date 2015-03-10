#ifndef GOCOMPONENT_H
#define GOCOMPONENT_H

#include "Bubblewrap/Base/GoBase.hpp"

namespace Bubblewrap
{
	namespace Base
	{
		class GoEntity;
		class ObjectRegister;
		class GoComponent
			: public GoBase
		{
			friend ObjectRegister;
		};
	}

}


#endif