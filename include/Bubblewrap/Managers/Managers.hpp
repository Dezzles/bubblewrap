#ifndef BUBBLEWRAP_MANAGERS_MANAGERS_HPP
#define BUBBLEWRAP_MANAGERS_MANAGERS_HPP

#include "Bubblewrap/Managers/Container.hpp"
#include "Bubblewrap/Render/Window.hpp"
#include "Bubblewrap/Events/EventManager.hpp"
#include "Bubblewrap/File/FileSystem.hpp"
namespace Bubblewrap
{
	namespace Game
	{
		class Game;
	}
	namespace Managers
	{
#define CREATE_MANAGER_CONTAINER( T, U ) \
	public: \
		/*! Gets the U manager container*/\
		MgrContainer<T> &Get ## U ## Manager () { Cnt ## U ## _.SetManager(this); return Cnt ## U ## _ ; } \
	private: \
		MgrContainer<T> Cnt ## U ## _;

#define CREATE_MANAGER( T, U ) \
	public: \
		/*! Gets the manager for U */ \
		T &Get ## U ## Manager () { return Cnt ## U ## _ ; } \
	private: \
		T Cnt ## U ## _;

		// static_assert ( is_base_of < BASE , DERIVED >::value, nameofthingy)

		/*! A container that handles various manager objects */
		class Managers
		{
		public:
			/*! Creates an instance of Managers*/
			Managers();

			CREATE_MANAGER_CONTAINER( Render::Window, Window );
			CREATE_MANAGER( Events::EventManager, Event );
			CREATE_MANAGER( File::FileSystem, File );

		public:
			/*! Gets the Game used
			\param The game object that is being used
			*/
			Game::Game* GetGame();

			/*! Sets the Game used 
			\param Game The game object that is being used
			*/
			void SetGame( Game::Game* Game );
		private:
			Game::Game* Game_;
		};

#undef CREATE_MANAGER
	}
}


#endif