#ifndef BASEMANAGER_HPP
#define BASEMANAGER_HPP

namespace Bubblewrap
{
	namespace Managers
	{
		class Managers;
		class BaseManager
		{
			friend Managers;
		public:
			BaseManager();
			Managers& GetManagers();
			void SetManager( Managers* Manager );
		private:
			Managers* Manager_;
		};


	}
}



#endif