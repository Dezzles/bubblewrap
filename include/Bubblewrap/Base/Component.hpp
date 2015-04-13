#ifndef BUBBLEWRAP_BASE_COMPONENT_HPP
#define BUBBLEWRAP_BASE_COMPONENT_HPP

#include "Bubblewrap/Base/Base.hpp"

namespace Bubblewrap
{
	namespace Base
	{
		class Entity;
		class ObjectRegister;
		//! Base component class that is the parent class of all game objects
		class Component
			: public GoBase
		{
			friend ObjectRegister;
		};
	}

}


#endif