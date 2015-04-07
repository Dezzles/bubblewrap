#include "Bubblewrap/Audio/SoundBuffer.hpp"

namespace Bubblewrap
{
	namespace Audio
	{
		SoundBuffer::SoundBuffer()
		{

		}

		void SoundBuffer::Initialise( Json::Value Params )
		{
			Base::Resource::Initialise( Params );
			REQUIRED_LOAD( String, Filename, filename );
		}

		void SoundBuffer::Copy( SoundBuffer* Target, SoundBuffer* Base )
		{
			Base::Resource::Copy( Target, Base );
			NAIVE_COPY( Filename );
		}

	}
}