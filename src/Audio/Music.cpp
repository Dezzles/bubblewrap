#include "Bubblewrap/Audio/Music.hpp"
#include "Bubblewrap/Base/Assert.hpp"
namespace Bubblewrap
{
	namespace Audio
	{
		Music::Music()
		{
			Attenuation_ = 0.0f;
			Loop_ = false;
			MinDistance_ = 0.0f;
			Pitch_ = 1.0f;
			Offset_ = 0.0f;
			Volume_ = 1.0f;
			Autoplay_ = false;
		}

		void Music::Initialise( Json::Value Params )
		{
			Base::GoBase::Initialise( Params );
			REQUIRED_LOAD( String, Filename, filename );
			OPTIONAL_LOAD( String, Position, position );
			OPTIONAL_LOAD( Float, Attenuation, attenuation );
			OPTIONAL_LOAD( Bool, Loop, loop );
			OPTIONAL_LOAD( Float, MinDistance, minDistance );
			OPTIONAL_LOAD( Float, Pitch, pitch );
			OPTIONAL_LOAD( Float, Offset, offset );
			OPTIONAL_LOAD( Float, Volume, volume );
			OPTIONAL_LOAD( Bool, Autoplay, autoplay );
		}

		void Music::Copy( Music* Target, Music* Base )
		{
			Base::GoBase::Copy( Target, Base );
			NAIVE_COPY( Filename );
			NAIVE_COPY( Position );
			NAIVE_COPY( Attenuation );
			NAIVE_COPY( Loop );
			NAIVE_COPY( MinDistance );
			NAIVE_COPY( Pitch );
			NAIVE_COPY( Offset );
			NAIVE_COPY( Volume );
			NAIVE_COPY( Autoplay );
			Target->IsDirty_ = true;
			
		}

		void Music::Play()
		{

		}

		void Music::Pause()
		{

		}

		void Music::Stop()
		{

		}

		Sound::Status Music::GetStatus()
		{
			return Sound::Status::Stopped;
		}
	}
}