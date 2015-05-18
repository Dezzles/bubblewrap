#ifndef BUBBLEWRAP_AUDIO_SOUND_HPP
#define BUBBLEWRAP_AUDIO_SOUND_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Component.hpp"
#include "Bubblewrap/Math/Vector2.hpp"

namespace Bubblewrap
{
	namespace Audio
	{
		class SoundBuffer;
		/*! The Sound class is designed to play sounds.
		Sound can have the following JSON parameters:
		- name \a Required - The name of the object
		- resource \a Optional - The name of the SoundBuffer resource that should be used to play
		- attenuation \a Optional
		- loop \a Optional (default false) - whether the music should loop
		- autoplay \a Optional (default false) - whether the music immediately
		- minDistance \a Optional
		- pitch \a Optional
		- offset \a Optional - where in the music play should be
		- position \a Optional - a plain text description of a Vector3 (e.g. "0 0.5 1.0")
		- volume \a Optional (default 1.0f) - volume of the music in the range 0.0 ... 1.0
		*/
		class Sound :
			public Base::Component
		{
		public:
			/*! Enum of the different statuses that a sound can take on*/
			enum class Status
			{
				/*! Sound is not currently playing */
				Stopped,
				/*! Sound is paused */
				Paused,
				/* Sound is playing */
				Playing
			};

			/*! Creates a Sound object*/
			Sound();
			/*! Initialises a Sound object
			\param Params A Json value containing the data to initialise the Sound object with
			*/
			void Initialise( Json::Value Params );
			CREATE_REGISTER( Sound );

			/*! Called during the OnAttach stage, this function will attempt to grab a SoundBuffer if Resource is set*/
			void OnAttach();


			PROTECTED_FIELD( std::string, Resource );
			PROTECTED_FIELD( SoundBuffer*, Buffer );

			PROTECTED_DIRTY_FIELD( float, Attenuation );
			PROTECTED_DIRTY_FIELD( bool, Loop );
			PROTECTED_DIRTY_FIELD( bool, Autoplay );
			PROTECTED_DIRTY_FIELD( float, MinDistance );
			PROTECTED_DIRTY_FIELD( float, Pitch );
			PROTECTED_DIRTY_FIELD( float, Offset );
			PROTECTED_DIRTY_FIELD( Math::Vector2f, Position );
			PROTECTED_DIRTY_FIELD( float, Volume );
			PROTECTED_DIRTY_FIELD( bool, PositionalSound );

			/*! Starts the sound playing if it isn't already */
			virtual void Play();

			/*! Pauses the sound */
			virtual void Pause();
			/*! Stops the sound */
			virtual void Stop();

			/*! Gets the current status of the sound
			\return The current status of the sound
			*/
			virtual Sound::Status GetStatus();
		protected:
			/*! Marks when a value has been changed */
			bool IsDirty_;
		};

	}
}


#endif