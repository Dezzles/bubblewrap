#ifndef BUBBLEWRAP_SOUNDBUFFER_HPP
#define BUBBLEWRAP_SOUNDBUFFER_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Resource.hpp"

namespace Bubblewrap
{
	namespace Audio
	{
		/*! The SoundBuffer class is designed to store sounds to be played by the Sound class.
		SoundBuffer can have the following JSON parameters:
		- name \a Required - The name of the object
		- Filename \a Required - The name of the sound file to load
		*/
		class SoundBuffer :
			public Base::Resource
		{
		public:
			/*! Creates a SoundBuffer object */
			SoundBuffer();

			/*! Initialises a SoundBuffer object
			\param Params A Json value containing the data to initialise the SoundBuffer object with
			*/
			void Initialise( Json::Value Params );
			CREATE_REGISTER( SoundBuffer );

			PROTECTED_FIELD( std::string, Filename );
		};

	}
}


#endif