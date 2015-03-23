#ifndef BUBBLEWRAP_SOUNDBUFFER_HPP
#define BUBBLEWRAP_SOUNDBUFFER_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Base.hpp"

namespace Bubblewrap
{
	namespace Sound
	{
		class SoundBuffer :
			public Base::GoBase
		{
		public:
			SoundBuffer();
			void Initialise( Json::Value Params );
			CREATE_REGISTER( SoundBuffer );

			void Update( float dt );

		};

	}
}


#endif