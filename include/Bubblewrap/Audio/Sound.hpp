#ifndef BUBBLEWRAP_SOUND_HPP
#define BUBBLEWRAP_SOUND_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Component.hpp"
#include "Bubblewrap/Math/Vector2.hpp"

namespace Bubblewrap
{
	namespace Audio
	{
		class SoundBuffer;
		class Sound :
			public Base::Component
		{
		public:
			enum class Status
			{
				Stopped,
				Paused,
				Playing
			};

			Sound();
			void Initialise( Json::Value Params );
			CREATE_REGISTER( Sound );

			void Update( float dt );
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

			virtual void Play();
			virtual void Pause();
			virtual void Stop();

			virtual Status GetStatus();
		protected:
			bool IsDirty_;
		};

	}
}


#endif