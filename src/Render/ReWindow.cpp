#include "Bubblewrap/Render/ReWindow.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		ReWindow::ReWindow( )
		{
			Window_ = new sf::RenderWindow( sf::VideoMode( 800, 600 ), "Bubblewrap Window" );
		}
		ReWindow::ReWindow( int Width, int Height )
		{
			Window_ = new sf::RenderWindow( sf::VideoMode( Width, Height ), "Bubblewrap Window" );
		}

		ReWindow::ReWindow( int Width, int Height, std::string Header )
		{
			Window_ = new sf::RenderWindow( sf::VideoMode( Width, Height ), Header );
		}
	}
}