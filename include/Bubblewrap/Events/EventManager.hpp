#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <functional>
#include <map>
#include <vector>
#include "Bubblewrap/Events/Event.hpp"
#include "Bubblewrap/Events/EventHandle.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		class Base;
		class Entity;
	}
	namespace Events
	{
		/*! Handles the passing around and storing of events. Events are processed after the Update stage. */
		class EventManager
		{
			friend EventHandle;
			typedef std::function<void( Event* )> EventFunctionDef;
		public:
			/* Creates an EventManager */
			EventManager();

			/*! Registers a function to be called when a given event type is processed.
				\param EventType The type of event that the function is looking for.
				\param EventFunction The function that should be called when an event of EventType is being processed.
				\returns A unique handle for the event registration.
			*/
			EventHandle RegisterEvent( unsigned int EventType, std::function<void( Event* )> EventFunction );

			/*! Adds an event to the event queue. 
			\param Event The event to send to the event queue
			*/
			void QueueEvent( Event Event );

			/*! Processes all events and sends them out to registered components.
			*/
			void ProcessEvents();
		private:
			void DeregisterEvent( unsigned int EventId );
			struct EventStruct
			{
				EventStruct(int EventId, EventFunctionDef EventFunction)
					: EventId_( EventId ), EventFunction_( EventFunction )
				{
					
				}
				unsigned int EventId_;
				std::function<void( Event* )> EventFunction_;
			};

			unsigned int NextEventId_;

			std::map<int, std::vector<EventStruct>> EventsCallbacks_;

			std::vector< Event* > EventQueue_;
		};
	}
}


#endif