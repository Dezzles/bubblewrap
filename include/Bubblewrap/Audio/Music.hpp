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
		class Music :
			public Base::Component
		{
		public:

			Music();
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