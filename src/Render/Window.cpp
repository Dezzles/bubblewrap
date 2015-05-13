#include "Bubblewrap/Render/Window.hpp"
#include "Bubblewrap/Managers/Managers.hpp"

#include "Bubblewrap/Events/Events.hpp"
#include "Bubblewrap/Events/EventManager.hpp"
#include "Bubblewrap/Render/Drawable.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		Window::Window( WindowSettings Settings )
			: Window_( nullptr ), Settings_( Settings )
		{
			ClearColour_ = Settings.Colour_;
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

		void* Window::GetInternalPointer()
		{
			return nullptr;
		}
	}
}