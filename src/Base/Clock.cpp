#include "Bubblewrap/Base/Clock.hpp"

namespace Bubblewrap
{
	namespace Base
	{
		void Clock::Copy( Clock* Target, Clock* Base )
		{
			GoBase::Copy( Target, Base );
		}

		Time Clock::GetElapsedTime()
		{
			return Time(0);
		}
	}
}