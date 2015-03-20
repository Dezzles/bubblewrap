#ifndef Texture_H
#define Texture_H

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Component.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		class Texture
			: public Base::Component
		{
		public:
			Texture();
			void Initialise(Json::Value Params);

			CREATE_REGISTER( Texture );

			virtual void Update( float dt );

		private:

		};
	}
}


#endif