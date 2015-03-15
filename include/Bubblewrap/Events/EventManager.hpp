#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <functional>
#include <map>
#include <vector>
#include "Bubblewrap/Events/Event.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		class Base;
		class Entity;
	}
	namespace Events
	{
		class EventManager
		{
			typedef std::function<void( Event* )> EventFunctionDef;
		public:
			unsigned int RegisterEvent( unsigned int EventType, std::function<void( Event* )> EventFunction );
			void DeregisterEvent( unsigned int EventId );

			void SendMessage( Event Event );

			void ProcessMessages();
		private:
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