#ifndef CLOCK_HPP
#define CLOCK_HPP
#include "Bubblewrap/Base/Time.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Defines.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		class Clock
			: public GoBase
		{
		public:
			CREATE_REGISTER( Clock );

		public:
			virtual Time GetElapsedTime();
			virtual void Update(float dt);
		};
	}
}


#endif