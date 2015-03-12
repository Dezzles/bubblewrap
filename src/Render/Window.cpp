#include "Bubblewrap/Render/Window.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		Window::Window()
		{
			Window_ = new sf::RenderWindow( sf::VideoMode( 800, 600 ), "Bubblewrap Window" );
		}
		Window::Window( int Width, int Height )
		{
			Window_ = new sf::RenderWindow( sf::VideoMode( Width, Height ), "Bubblewrap Window" );
		}

		Window::Window( int Width, int Height, std::string Header )
		{
			Window_ = new sf::RenderWindow( sf::VideoMode( Width, Height ), Header );
		}

		Window::Window( WindowSettings Settings )
		{
			Window_ = new sf::RenderWindow( sf::VideoMode( Settings.Width_, Settings.Height_ ), Settings.Title_ );
		}

		void Window::Update( float dt )
		{
			Window_->clear();
		}

		void Window::Display()
		{
			Window_->display();
		}

		void Window::HandleEvents()
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
		void Window::Do( std::function<void( sf::RenderWindow& Window )> Function )
		{
			Function( *Window_ );
		}
	}
}