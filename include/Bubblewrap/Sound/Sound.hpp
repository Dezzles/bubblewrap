#ifndef BUBBLEWRAP_SOUND_HPP
#define BUBBLEWRAP_SOUND_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Base.hpp"

namespace Bubblewrap
{
	namespace Sound
	{
		class Sound :
			public Base::GoBase
		{
		public:
			Sound();
			void Initialise( Json::Value Params );
			CREATE_REGISTER( Sound );

			void Update( float dt );

		};

	}
}


#endif