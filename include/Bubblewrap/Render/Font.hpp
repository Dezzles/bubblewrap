#ifndef BUBBLEWRAP_RENDER_FONT_HPP
#define BUBBLEWRAP_RENDER_FONT_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Resource.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Render/Colour.hpp"
#include "Bubblewrap/Render/Window.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		/*! Resource for storing of fonts */
		class Font
			: public Base::Resource
		{
		public:
			/* Creates a new instance of Font */
			Font();

			/*! Initialises a font
			\param Params A Json value containing the data to initialise the font with
			*/
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Font );

		};
	}
}




#endif