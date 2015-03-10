#ifndef GOGAME_H
#define GOGAME_H

#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Managers/MgrManagers.hpp"

namespace Bubblewrap
{
	namespace Game
	{
 		struct GoGameSettings
		{
			int WindowCount_ = 0;
			Render::ReWindow::WindowSettings* WindowSettings_ = nullptr;
			std::string BaseJson;
			std::function<void( Base::ObjectRegister* )> TypeRegistration_;
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