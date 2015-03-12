#ifndef Component_H
#define Component_H

#include "Bubblewrap/Base/Base.hpp"

namespace Bubblewrap
{
	namespace Base
	{
		class Entity;
		class ObjectRegister;
		class Component
			: public GoBase
		{
			friend ObjectRegister;
		};
	}

}


#endif