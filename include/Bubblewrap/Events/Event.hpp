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
			Event( int EventType, EventData* Data );

			int GetEventType() const;
			EventData* GetData() const;
			~Event();
		private:
			int EventType_;
			EventData* Data_;

		};
	}
}


#endif