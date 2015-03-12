#ifndef MGRMANAGERS_H
#define MGRMANAGERS_H
#include "Bubblewrap/Managers/MgrContainer.hpp"
#include "Bubblewrap/Render/ReWindow.hpp"
namespace Bubblewrap
{
	namespace Managers
	{
#define CREATE_MANAGER( T, U ) \
	public: \
		MgrContainer<T> &Get ## U ## Manager () { return Cnt ## U ## _ ; } \
	private: \
		MgrContainer<T> Cnt ## U ## _;

		// static_assert ( is_base_of < BASE , DERIVED >::value, nameofthingy)


		class MgrManagers
		{
		public:
			MgrManagers();

			CREATE_MANAGER(Render::ReWindow, Window);
		};

#undef CREATE_MANAGER
	}
}


#endif