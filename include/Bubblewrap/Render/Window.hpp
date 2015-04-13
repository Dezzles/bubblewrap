#ifndef BUBBLEWRAP_RENDER_WINDOW_HPP
#define BUBBLEWRAP_RENDER_WINDOW_HPP


#include "Bubblewrap/Managers/BaseManager.hpp"
#include <functional>
#include <vector>

namespace Bubblewrap
{
	namespace Render
	{
		class Drawable;
		/*! Class representing a window 
		*/
		class Window 
			: public Managers::BaseManager
		{
		public:
			/*! Settings used for constructing a window 
			*/
			struct WindowSettings
			{
				/*! Width for the window*/
				int Width_;
				/*! Height for the window */
				int Height_;
				/*! Title to be displayed on the window */
				std::string Title_;
				/*! Name of the window */
				std::string Name_;
			};
			/*! Creates a window
			\param Settings All of the settings required to create the window
			*/
			Window( WindowSettings Settings );

			/*! Updates the window with timestep dt in seconds */
			virtual void Update( float dt );

			/*! Causes the window to display currently drawn objects*/
			virtual void Display();

			/*! Causes the window to handle received input events */
			virtual void HandleEvents();

			/*! Adds a drawable item to the queue to be rendered */
			void AddToQueue( Render::Drawable* Draw );

			/*! Gets the Window_ pointer with a specific type. Bad casting may result in undefined behaviour.
			\tparam T_ The type that the window should be cast to
			\returns The internal window cast to T 
			*/
			template <typename T_>
			T_* GetWindow()
			{
				return static_cast< T_* >( Window_ );
			}
		protected:
			/*! A pointer to the internal window created */
			void* Window_;
			/*! The queue of drawable objects to be rendered */
			std::vector<Render::Drawable*> RenderQueue_;
		};

	}
}

#endif