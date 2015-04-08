#ifndef GOGAME_H
#define GOGAME_H

#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
#include <functional>
#include <vector>
namespace Bubblewrap
{
	namespace Game
	{
		/*! Struct for setting up all settings related to creation of a game.*/
 		struct GameSettings
		{
			/*! The number of windows to be created. */
			int WindowCount_ = 0;
			/*! A pointer to an array of window settings */
			Render::Window::WindowSettings* WindowSettings_ = nullptr;
			/*! A list of all packages that should be loaded */
			std::vector<std::string> Packages_;
			/*! A list of all resource sets that should be loaded */
			std::vector<std::string> Resources_;
			/*! A list of all module registers that should be loaded */
			std::vector<std::function<void( void* )>> Registers_;
			/*! A function that should contain any addition object registrations */
			std::function<void( Base::ObjectRegister* )> TypeRegistration_;
			/*! The package and name of the base entity that should be loaded at start up, in the format "packageName:entityName"*/
			std::string BaseObject_;
		};

		/*! Object that runs all game behaviour */
		class Game
		{
		public:
			/*! Initialises the base game object */
			Game();
			/*! Starts the game.
			\param Settings The settings that dicatate how the game runs. */
			void Run( GameSettings Settings );
		private:
			Base::ObjectRegister Register_;

			Managers::Managers Managers_;
		};
	}
}


#endif