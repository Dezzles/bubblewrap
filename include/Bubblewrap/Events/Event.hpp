#ifndef EVMESSAGE_HPP
#define EVMESSAGE_HPP

namespace Bubblewrap
{
	namespace Events
	{
		namespace EventTypes
		{
			enum EventTypes : unsigned int
			{
				Input,


				LastEvent
			};
		}

		class EventManager;
		class EventData
		{ };

		class Event
		{
			friend EventManager;
		public:
			Event( EventTypes::EventTypes EventType, EventData* Data );

			EventTypes::EventTypes GetEventType() const;
			EventData* GetData() const;
			~Event();
		private:
			EventTypes::EventTypes EventType_;
			EventData* Data_;

		};
	}
}


#endif