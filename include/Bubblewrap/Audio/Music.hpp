#ifndef BUBBLEWRAP_AUDIO_MUSIC_HPP
#define BUBBLEWRAP_AUDIO_MUSIC_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Component.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Audio/Sound.hpp"

namespace Bubblewrap
{
	namespace Audio
	{
		/*! The Music class is designed to play longer sounds such as music.
		Music can have the following JSON parameters:
		- name \a Required - The name of the object
		- filename \a Required - The filename containing the music to play
		- attenuation \a Optional
		- loop \a Optional (default false) - whether the music should loop
		- autoplay \a Optional (default false) - whether the music immediately
		- minDistance \a Optional
		- pitch \a Optional 
		- offset \a Optional - where in the music play should be
		- position \a Optional - a plain text description of a Vector3 (e.g. "0 0.5 1.0")
		- volume \a Optional (default 1.0f) - volume of the music in the range 0.0 ... 1.0
		*/
		class Music :
			public Base::Component
		{
		public:

			Music();
			/*! Initialises a Music object
			\param Params A Json value containing the data to initialise the Music object with
			*/
			void Initialise( Json::Value Params );
			CREATE_REGISTER( Music );

			PROTECTED_READ_FIELD( std::string, Filename );
			PROTECTED_DIRTY_FIELD( float, Attenuation );
			PROTECTED_DIRTY_FIELD( bool, Loop );
			PROTECTED_DIRTY_FIELD( bool, Autoplay );
			PROTECTED_DIRTY_FIELD( float, MinDistance );
			PROTECTED_DIRTY_FIELD( float, Pitch );
			PROTECTED_DIRTY_FIELD( float, Offset );
			PROTECTED_DIRTY_FIELD( Math::Vector2f, Position );
			PROTECTED_DIRTY_FIELD( float, Volume );

			/*! Starts the music playing if it isn't already */
			virtual void Play();
			
			/*! Pauses the music */
			virtual void Pause();
			/*! Stops the music */
			virtual void Stop();

			/*! Gets the current status of the music
				\return The current status of the music
			*/
			virtual Sound::Status GetStatus();
	
		protected:
			/*! Marks when a value has been changed */
			bool IsDirty_;
		};

	}
}


#endif