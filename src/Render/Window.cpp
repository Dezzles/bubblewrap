#include "Bubblewrap/Render/Window.hpp"
#include "Bubblewrap/Managers/Managers.hpp"

#include "Bubblewrap/Events/Events.hpp"
#include "Bubblewrap/Events/EventManager.hpp"
#include "Bubblewrap/Render/Drawable.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		Window::Window()
			: Window_( nullptr )
		{

		}
		Window::Window( int Width, int Height )
			: Window_( nullptr )
		{

		}

		Window::Window( int Width, int Height, std::string Header )
			: Window_( nullptr )
		{

		}

		Window::Window( WindowSettings Settings )
			: Window_( nullptr )
		{

		}

		void Window::Update( float dt )
		{

		}

		void Window::Display()
		{
			std::sort( RenderQueue_.begin(), RenderQueue_.end(), 
				[ ]( Render::Drawable* objA, Render::Drawable* objB )
			{
				return objA->GetDrawOrder() < objB->GetDrawOrder();
			} );

			unsigned int uCount = RenderQueue_.size();
			for ( unsigned int Idx = 0; Idx < uCount; ++Idx )
				RenderQueue_[ Idx ]->Draw();

			RenderQueue_.clear();
		}

		void Window::HandleEvents()
		{


		}

		void Window::AddToQueue( Render::Drawable* Draw )
		{
			RenderQueue_.push_back( Draw );
		}
	}
}