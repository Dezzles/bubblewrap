#ifndef GOGAME_H
#define GOGAME_H

#include "Bubblewrap/Base/ObjectRegister.hpp"

namespace Bubblewrap
{
	namespace Game
	{
		class GoGame
		{
		public:
			GoGame();
			void Run();
		private:
			Base::ObjectRegister Register_;
		};
	}
}


#endif