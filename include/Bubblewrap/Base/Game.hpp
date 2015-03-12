#ifndef GOGAME_H
#define GOGAME_H

#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Managers/Managers.hpp"

namespace Bubblewrap
{
	namespace Game
	{
 		struct GoGameSettings
		{
			int WindowCount_ = 0;
			Render::Window::WindowSettings* WindowSettings_ = nullptr;
			std::vector<std::string> Packages_;
			std::function<void( Base::ObjectRegister* )> TypeRegistration_;
			std::string BaseObject_;
		};
		class GoGame
		{
		public:
			GoGame();
			void Run( GoGameSettings Settings );
		private:
			Base::ObjectRegister Register_;

			Managers::MgrManagers Managers_;
		};
	}
}


#endif