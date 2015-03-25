#ifndef BUBBLEWRAP_MUSIC_HPP
#define BUBBLEWRAP_MUSIC_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Component.hpp"

namespace Bubblewrap
{
	namespace Sound
	{
		class Music :
			public Base::Component
		{
		public:
			Music();
			void Initialise( Json::Value Params );
			CREATE_REGISTER( Music );

			void Update( float dt );

		};

	}
}


#endif