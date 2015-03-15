#include "Bubblewrap/Events/Event.hpp"

namespace Bubblewrap
{
	namespace Events
	{
		Event::Event( EventTypes::EventTypes EventType, EventData* Data )
		{
			EventType_ = EventType;
			Data_ = Data;
		}

		Event::~Event()
		{
		}

		EventTypes::EventTypes Event::GetEventType() const
		{
			return EventType_;
		}

		EventData* Event::GetData() const
		{
			return Data_;
		}

	}
}