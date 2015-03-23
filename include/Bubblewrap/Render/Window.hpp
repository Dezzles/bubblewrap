#ifndef WINDOW_HPP
#define WINDOW_HPP


#include "Bubblewrap/Managers/BaseManager.hpp"
#include <functional>
#include <vector>

namespace Bubblewrap
{
	namespace Render
	{
		class Drawable;
		class Window 
			: public Managers::BaseManager
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

			virtual void Update( float dt );
			virtual void Display();
			virtual void HandleEvents();
			void AddToQueue( Render::Drawable* Draw );
			template <typename T>
			T* GetWindow()
			{
				return static_cast< T* >( Window_ );
			}
		protected:
			void* Window_;
			std::vector<Render::Drawable*> RenderQueue_;
		};

	}
}

#endif