#ifndef BUBBLEWRAP_MUSIC_HPP
#define BUBBLEWRAP_MUSIC_HPP

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
		- name <i>Required</i> - The name of the object
		- attenuation - a plain text description of a Vector3 (e.g. "0 0.5 1.0")
		- children - a json array of entities
		- components - a json array of components

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

			void Update( float dt );

			PROTECTED_DIRTY_FIELD( float, Attenuation );
			PROTECTED_DIRTY_FIELD( bool, Loop );
			PROTECTED_DIRTY_FIELD( bool, Autoplay );
			PROTECTED_DIRTY_FIELD( float, MinDistance );
			PROTECTED_DIRTY_FIELD( float, Pitch );
			PROTECTED_DIRTY_FIELD( float, Offset );
			PROTECTED_DIRTY_FIELD( Math::Vector2f, Position );
			PROTECTED_DIRTY_FIELD( float, Volume );

			virtual void Play();
			virtual void Pause();
			virtual void Stop();
			virtual Sound::Status GetStatus();
	
		protected:
			std::string Filename_;
			bool IsDirty_;
		};

	}
}


#endif