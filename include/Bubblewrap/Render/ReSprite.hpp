#ifndef RESPRITE_H
#define RESPRITE_H

#include "SFML/Graphics.hpp"
#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/GoComponent.hpp"
#include "Bubblewrap/Math/MaVector.hpp"
#include "Bubblewrap/Render/ReColour.hpp"
#include "Bubblewrap/Render/ReWindow.hpp"
#include "Bubblewrap/Render/ReTexture.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		class ReSprite
			: public Base::GoComponent
		{
		public:
			ReSprite();
			void Initialise( Json::Value Params );

			CREATE_REGISTER( ReSprite );

			virtual void Update( float dt );
			virtual void OnAttach();


			ReColour GetColour();
			void SetColour( ReColour Colour );

			Math::Vector2f GetSize();
			void SetSize( Math::Vector2f Size );

			void SetWindow( std::string Name );
			void SetWindow( ReWindow* Window );

			void SetTexture( ReTexture* Texture );
		private:

			sf::RectangleShape Shape_;
			Math::Vector2f Size_;
			ReColour Colour_;
			ReWindow* Window_;

			ReTexture* Texture_;

			std::string TextureName_;
		};
	}
}


#endif