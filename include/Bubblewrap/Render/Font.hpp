#ifndef BUBBLEWRAP_FONT_HPP
#define BUBBLEWRAP_FONT_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Resource.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Render/Colour.hpp"
#include "Bubblewrap/Render/Window.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		class Font
			: public Base::Resource
		{
		public:
			Font();
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Font );

			virtual void Update( float dt );
			virtual void OnAttach();

		protected:

		};
	}
}




#endif