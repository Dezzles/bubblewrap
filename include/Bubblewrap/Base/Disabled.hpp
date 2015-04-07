#ifndef BUBBLEWRAP_DISABLED_HPP
#define CLOCK_HPP
#include "Bubblewrap/Base/Base.hpp"
#include "Defines.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		//!  Class loaded when a non-standard feature hasn't been implemented by any loaded modules
		/*!
			The Disabled class is designed to let the user know when they are attempting to load in
			an unimplemented feature. Some examples of unimplemented are Texture, Sound, Music etc.
			Some resources can also be loaded in as Disabled
		*/
		template <typename T_>
		class Disabled
			: public T_
		{
		public:
			CREATE_REGISTER_DISABLED( T_, T_ );
		};
	}
}


#endif