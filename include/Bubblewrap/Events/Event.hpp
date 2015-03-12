#ifndef EVMESSAGE_HPP
#define EVMESSAGE_HPP

namespace Bubblewrap
{
	namespace Events
	{
		class Manager;
		class EventData
		{ };

		class Event
		{
			friend Manager;
		public:
			Event( int EventType, EventData* Data );


			int GetEventType() const;
			EventData* GetData() const;
		private:
			int EventType_;
			EventData* Data_;

			Event( const Event& Other )
			{
			}
		};
	}
}


#endif