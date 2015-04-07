#ifndef BUBBLEWRAP_EVENTHANDLE_HPP
#define BUBBLEWRAP_EVENTHANDLE_HPP

namespace Bubblewrap
{
	namespace Events
	{
		class EventManager;
		/*! Used to store a handle to a registered event. This will automatically
			release the registered event when all instances of an EventHandle have
			been descoped, or destroyed
		*/
		class EventHandle
		{
			friend EventManager;
		public:
			/*! Creates the default EventHandle */
			EventHandle();
			/*! Copies an EventHandle */
			EventHandle( const EventHandle& Other );
			/*! When descoped this may cause the EventManager's event to be released */
			~EventHandle();
			/*! When descoped this may cause the EventManager's event to be released */
			void Destroy();

		private:
			int* UseCounter_;
			unsigned int Handle_;
			EventManager* Manager_;

		};
	}
}



#endif 