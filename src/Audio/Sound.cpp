#include "Bubblewrap/Audio/Sound.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"
namespace Bubblewrap
{
	namespace Audio
	{
		Sound::Sound()
		{
			Attenuation_ = 0.0f;
			Loop_ = false;
			MinDistance_ = 0.0f;
			Pitch_ = 1.0f;
			Offset_ = 0.0f;
			Volume_ = 1.0f;
			Autoplay_ = false;
			PositionalSound_ = true;
		}

		void Sound::Initialise( Json::Value Params )
		{
			OPTIONAL_LOAD( String, Resource, resource );
			OPTIONAL_LOAD( String, Position, position );
			OPTIONAL_LOAD( Float, Attenuation, attenuation );
			OPTIONAL_LOAD( Bool, Loop, loop );
			OPTIONAL_LOAD( Float, MinDistance, minDistance );
			OPTIONAL_LOAD( Float, Pitch, pitch );
			OPTIONAL_LOAD( Float, Offset, offset );
			OPTIONAL_LOAD( Float, Volume, volume );
			OPTIONAL_LOAD( Bool, Autoplay, autoplay );
			OPTIONAL_LOAD( Bool, PositionalSound, positionalSound );
		}

		void Sound::Copy( Sound* Target, Sound* Base )
		{
			NAIVE_COPY( Resource );
			NAIVE_COPY( Position );
			NAIVE_COPY( Attenuation );
			NAIVE_COPY( Loop );
			NAIVE_COPY( MinDistance );
			NAIVE_COPY( Pitch );
			NAIVE_COPY( Offset );
			NAIVE_COPY( Volume );
			NAIVE_COPY( Autoplay );
			NAIVE_COPY( PositionalSound );
			Target->IsDirty_ = true;
		}

		void Sound::OnAttach()
		{
			if ( Resource_ != "" )
				Buffer_ = (SoundBuffer*)GetRegister().GetResource( Resource_ );
		}

		void Sound::Play()
		{

		}

		void Sound::Stop()
		{

		}

		void Sound::Pause()
		{

		}

		Sound::Status Sound::GetStatus()
		{
			return Sound::Status::Stopped;
		}
	}
}