#ifndef CLOCK_HPP
#define CLOCK_HPP
#include "Bubblewrap/Base/Time.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Defines.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		//!  Basis for clocks to be used by Game.
		/*!
			This Clock function is not fully implemented and should be overwritten by
			at least one package loaded by Bubblewrap.
		*/
		class Clock
			: public GoBase
		{
		public:
			CREATE_REGISTER( Clock );

		public:
			//! Returns a Time object. This implementation will always return a Time 0.
			virtual Time GetElapsedTime();
		};
	}
}


#endif