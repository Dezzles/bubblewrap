#ifndef RETEXTURE_H
#define RETEXTURE_H

#include "SFML/Graphics.hpp"
#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/GoComponent.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		class ReTexture
			: public Base::GoComponent
		{
		public:
			ReTexture();
			void Initialise(Json::Value Params);

			CREATE_REGISTER( ReTexture );

			virtual void Update( float dt );

			sf::Texture* GetTexture();
		private:

			sf::Texture Texture_;

		};
	}
}


#endif