#include "Bubblewrap/Managers/BaseManager.hpp"
#include <assert.h>

namespace Bubblewrap
{
	namespace Managers
	{
		BaseManager::BaseManager()
		{
			Manager_ = nullptr;
		}

		Managers &BaseManager::GetManagers()
		{
			return *Manager_;
		}

		void BaseManager::SetManager( Managers* Manager )
		{
			assert( Manager_ == nullptr );
			Manager_ = Manager;
		}

	}
}