#ifndef Drawable_HPP
#define Drawable_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Component.hpp"
#include "Bubblewrap/Render/Window.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		/*! A base class that any object that will be drawn should be derived from.
			Drawables can have the following JSON parameters :
			- window - the name of the window that should be drawn to
			- drawOrder - the order in which this draw object should be drawn
		*/
		class Drawable
			: public Base::Component
		{
		public:
			/*! Initialises a new drawable object. */
			Drawable();
			/*! Initialises a drawable
			\param Params A Json value containing the data to initialise the entity with
			*/
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Drawable );

			/*! Updates the drawable with timestep dt in seconds. This will, if Visible is true, 
				add the drawable to the draw queue.
			\param dt The timestep in seconds 
			*/
			virtual void Update( float dt );

			/*! Sets the window used for rendering
			\param Name The name of the window that should be used.
			*/
			void SetWindow( std::string Name );

			/*! Sets the window used for rendering
			\param Window A pointer to the window that should be used for rendering
			*/
			void SetWindow( Window* Window );

			/*! Gets the current draw order for the drawable object
			\returns The draw order of this object
			*/
			int GetDrawOrder();
			/*! Sets the draw order for the drawable object
			\param DrawOrder The new draw order to be used
			*/
			void SetDrawOrder( int DrawOrder );

			/*! Gets whether the drawable object is currently visible (i.e. being rendered)
			\returns The visible status of the object
			*/
			bool GetVisible();
			/*! Sets whether the drawable object is currently visible (i.e. being rendered) 
			\param Visible The new visibility of this object.
			*/
			void SetVisible( bool Visible );

			/*! Draws the drawable object 
			*/
			virtual void Draw();
		protected:
			/*! Indicates whether a drawable should be rendered or not. */
			bool Visible_;
			/*! Indicates the draw order. */
			int DrawOrder_;
			/*! A pointer to the window that the drawable will draw on. */
			Window* Window_;
			/*! The name of the window the drawable should draw against. Used for loading purposes.*/
			std::string WindowName_;
		};
	}
}


#endif