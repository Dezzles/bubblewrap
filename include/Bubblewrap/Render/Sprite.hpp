#ifndef Sprite_H
#define Sprite_H

#include "SFML/Graphics.hpp"
#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/Drawable.hpp"
#include "Bubblewrap/Math/Vector.hpp"
#include "Bubblewrap/Render/Colour.hpp"
#include "Bubblewrap/Render/Window.hpp"
#include "Bubblewrap/Render/Texture.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		class Sprite
			: public Drawable
		{
		public:
			Sprite();
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Sprite );

			virtual void Update( float dt );
			virtual void OnAttach();


			Colour GetColour();
			void SetColour( Colour Colour );

			Math::Vector2f GetSize();
			void SetSize( Math::Vector2f Size );

			void SetTexture( Texture* Texture );
		private:

			sf::RectangleShape Shape_;
			Math::Vector2f Size_;
			Colour Colour_;

			Texture* Texture_;

			std::string TextureName_;
		};
	}
}


#endif