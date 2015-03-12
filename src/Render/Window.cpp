#include "Bubblewrap/Render/ReWindow.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		ReWindow::ReWindow()
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

		ReWindow::ReWindow( WindowSettings Settings )
		{
			Window_ = new sf::RenderWindow( sf::VideoMode( Settings.Width_, Settings.Height_ ), Settings.Title_ );
		}

		void ReWindow::Update( float dt )
		{
			Window_->clear();
		}

		void ReWindow::Display()
		{
			Window_->display();
		}

		void ReWindow::HandleEvents()
		{
			sf::Event event;
			while ( Window_->pollEvent( event ) )
			{
				// sm->Input( event );
				//if ( event.type == sf::Event::Closed )
				//window.close();
				if ( ( event.type == sf::Event::KeyPressed ) && ( event.key.code == sf::Keyboard::Escape ) )
				{

				}
			}

		}
		void ReWindow::Do( std::function<void( sf::RenderWindow& Window )> Function )
		{
			Function( *Window_ );
		}
	}
}