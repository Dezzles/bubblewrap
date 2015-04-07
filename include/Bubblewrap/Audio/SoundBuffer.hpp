#ifndef BUBBLEWRAP_SOUNDBUFFER_HPP
#define BUBBLEWRAP_SOUNDBUFFER_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Resource.hpp"

namespace Bubblewrap
{
	namespace Audio
	{
		class SoundBuffer :
			public Base::Resource
		{
		public:
			SoundBuffer();
			void Initialise( Json::Value Params );
			CREATE_REGISTER( SoundBuffer );

			void Update( float dt );
			virtual void OnAttach();

			PROTECTED_FIELD( std::string, Filename );
		};

	}
}


#endif