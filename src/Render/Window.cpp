#include "Bubblewrap/Render/Window.hpp"
#include "Bubblewrap/Managers/Managers.hpp"

#include "Bubblewrap/Events/Events.hpp"
#include "Bubblewrap/Events/EventManager.hpp"

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
				if ( ( event.type == sf::Event::KeyPressed ) )
				{
					auto code = Bubblewrap::Events::TranslateKey( event.key.code );
					printf( "sf::KeyDown\n" );
					Events::InputData* newEvent = new Events::InputData();
					newEvent->InputType_ = Events::InputData::InputType::KeyDown;
					newEvent->Key_ = Bubblewrap::Events::TranslateKey( event.key.code );
					newEvent->Alt_ = event.key.alt;
					newEvent->Control_ = event.key.control;
					newEvent->Shift_ = event.key.shift;
					Events::Event evt = Events::Event( Events::EventTypes::Input, newEvent );
					GetManagers().GetEventManager().SendMessage( evt );
				}
				else if ( ( event.type == sf::Event::KeyReleased ) )
				{
					auto code = Bubblewrap::Events::TranslateKey( event.key.code );
					printf( "sf::KeyUp\n" );
					Events::InputData* newEvent = new Events::InputData();
					newEvent->InputType_ = Events::InputData::InputType::KeyUp;
					newEvent->Key_ = Bubblewrap::Events::TranslateKey( event.key.code );
					newEvent->Alt_ = event.key.alt;
					newEvent->Control_ = event.key.control;
					newEvent->Shift_ = event.key.shift;
					Events::Event evt = Events::Event( Events::EventTypes::Input, newEvent );
					GetManagers().GetEventManager().SendMessage( evt );
				}
			}

		}
		void Window::Do( std::function<void( sf::RenderWindow& Window )> Function )
		{
			Function( *Window_ );
		}
	}
}