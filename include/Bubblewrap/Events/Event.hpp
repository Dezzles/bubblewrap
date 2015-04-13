#ifndef BUBBLEWRAP_EVENT_EVENT_HPP
#define BUBBLEWRAP_EVENT_EVENT_HPP

namespace Bubblewrap
{
	namespace Events
	{
		namespace EventTypes
		{
			/*!  Types of events thrown by the base Bubblewrap engine
			*/
			enum EventTypes : unsigned int
			{
				Input, /* Events thrown based on input changes */


				LastEvent /* Last event Bubblewrap uses. New events should be greater than LastEvent */
			};
		}

		class EventManager;
		class EventData
		{ };

		/*! Contains information about an event being passed around
		*/
		class Event
		{
			friend EventManager;
		public:
			/*! Creates a new Event
				\param EventType The type of event being created
				\param Data A pointer to a class that contains additional information about the event. This is destroyed by the EventManager after the event is processed.
			*/
			Event( int EventType, EventData* Data );

			/*! Gets the type of event that this event represents.
			*/
			int GetEventType() const;
			/*! Gets a pointer to the data this event was created with. Nullptr is a valid value.
			\returns Pointer to the event data stored.
			*/
			EventData* GetData() const;

			/*! Destroys the event
			*/
			~Event();
		private:
			int EventType_;
			EventData* Data_;

		};
	}
}


#endif