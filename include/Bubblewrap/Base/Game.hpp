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
 		struct GoGameSettings
		{
			int WindowCount_ = 0;
			Render::Window::WindowSettings* WindowSettings_ = nullptr;
			std::vector<std::string> Packages_;
			std::vector<std::function<void(void*)>> Registers_;
			std::function<void( Base::ObjectRegister* )> TypeRegistration_;
			std::string BaseObject_;
		};
		class Game
		{
		public:
			Game();
			void Run( GoGameSettings Settings );
		private:
			Base::ObjectRegister Register_;

			Managers::Managers Managers_;
		};
	}
}


#endif