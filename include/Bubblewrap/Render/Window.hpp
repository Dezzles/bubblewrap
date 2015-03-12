#ifndef Window_H
#define Window_H

#include "SFML/Graphics.hpp"
#include <functional>
namespace Bubblewrap
{
	namespace Render
	{
		class Window
		{
		public:
			struct WindowSettings
			{
				int Width_;
				int Height_;
				std::string Title_;
				std::string Name_;
			};

			Window();
			Window( int Width, int Height );
			Window( int Width, int Height, std::string Header );
			Window( WindowSettings Settings );

			void Update( float dt );
			void Display();
			void HandleEvents();
			void Do( std::function<void( sf::RenderWindow& Window )> Function );

			template <typename T>
			T* GetWindow()
			{
				return dynamic_cast< T* >( Window_ );
			}
		private:

			sf::RenderWindow* Window_;

		};

	}
}

#endif