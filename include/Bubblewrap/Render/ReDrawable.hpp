#ifndef REDRAWABLE_HPP
#define REDRAWABLE_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/GoComponent.hpp"
#include "Bubblewrap/Render/ReWindow.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		class ReDrawable
			: public Base::GoComponent
		{
		public:
			ReDrawable();
			void Initialise( Json::Value Params );

			CREATE_REGISTER( ReDrawable );

			virtual void Update( float dt );
			virtual void OnAttach();


			void SetWindow( std::string Name );
			void SetWindow( ReWindow* Window );
		protected:

			ReWindow* Window_;
			std::string WindowName_;
		};
	}
}


#endif