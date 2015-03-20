#include "Bubblewrap/Base/Time.hpp"

namespace Bubblewrap
{
	namespace Base
	{
		float Time::AsSeconds()
		{
			return ElapsedTime_;
		}

		Time::Time( float dt )
		{
			ElapsedTime_ = dt;
		}
	}
}