#include "Bubblewrap/Events/Event.hpp"

namespace Bubblewrap
{
	namespace Events
	{
		Event::Event( int EventType, EventData* Data )
		{
			EventType_ = EventType;
		}


		int Event::GetEventType() const
		{
			return EventType_;
		}

		EventData* Event::GetData() const
		{
			return Data_;
		}

	}
}