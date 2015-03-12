#ifndef Drawable_HPP
#define Drawable_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Component.hpp"
#include "Bubblewrap/Render/Window.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		class Drawable
			: public Base::Component
		{
		public:
			Drawable();
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Drawable );

			virtual void Update( float dt );
			virtual void OnAttach();


			void SetWindow( std::string Name );
			void SetWindow( Window* Window );
		protected:

			Window* Window_;
			std::string WindowName_;
		};
	}
}


#endif