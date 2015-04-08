#ifndef BASEMANAGER_HPP
#define BASEMANAGER_HPP

namespace Bubblewrap
{
	namespace Managers
	{
		class Managers;
		/*! Base manager class that can be attached to Managers */
		class BaseManager
		{
			friend Managers;
		public:

			/*! Creates a new manager*/
			BaseManager();
			/*! Returns a reference to the Managers that this is attached to */
			Managers& GetManagers();
			/*! Sets that manager that this is attached to
			\param Manager The managers that this manager is attached to
			*/
			void SetManager( Managers* Manager );
		private:
			Managers* Manager_;
		};


	}
}



#endif