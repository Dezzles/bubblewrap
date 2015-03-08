#ifndef REWINDOW_H
#define REWINDOW_H

#include "SFML/Graphics.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		class ReWindow
		{
		public:
			ReWindow( );
			ReWindow( int Width, int Height );
			ReWindow( int Width, int Height, std::string Header );

		private:

			sf::RenderWindow* Window_;

		};

	}
}

#endif