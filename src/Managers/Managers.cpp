#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Base/Game.hpp"

namespace Bubblewrap
{
	namespace Managers
	{
		Managers::Managers()
			: Game_(nullptr)
		{
			
		}

		Game::Game* Managers::GetGame()
		{
			return Game_;
		}

		void Managers::SetGame( Game::Game* Game )
		{
			if (Game_ == nullptr )
				Game_ = Game;
		}
	}
}