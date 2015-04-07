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
			/*! Registers a function to be called when a given event type is processed.
				\param EventType The type of event that the function is looking for.
				\param EventFunction The function that should be called when an event of EventType is being processed.
				\returns A unique handle for the event registration. Deregister should be called with this value when an object is no longer interested in the event.
			*/
			EventHandle RegisterEvent( unsigned int EventType, std::function<void( Event* )> EventFunction );

			void SendMessage( Event Event );

			void ProcessMessages();
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