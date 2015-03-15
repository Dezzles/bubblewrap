#ifndef MGRMANAGERS_H
#define MGRMANAGERS_H
#include "Bubblewrap/Managers/Container.hpp"
#include "Bubblewrap/Render/Window.hpp"
#include "Bubblewrap/Events/EventManager.hpp"
namespace Bubblewrap
{
	namespace Managers
	{
#define CREATE_MANAGER_CONTAINER( T, U ) \
	public: \
		MgrContainer<T> &Get ## U ## Manager () { Cnt ## U ## _.SetManager(this); return Cnt ## U ## _ ; } \
	private: \
		MgrContainer<T> Cnt ## U ## _;

#define CREATE_MANAGER( T, U ) \
	public: \
		T &Get ## U ## Manager () { return Cnt ## U ## _ ; } \
	private: \
		T Cnt ## U ## _;

		// static_assert ( is_base_of < BASE , DERIVED >::value, nameofthingy)


		class Managers
		{
		public:
			Managers();

			CREATE_MANAGER_CONTAINER( Render::Window, Window );
			CREATE_MANAGER( Events::EventManager, Event );
		};

#undef CREATE_MANAGER
	}
}


#endif