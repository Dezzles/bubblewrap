#ifndef EVTMESSAGE_H
#define EVTMESSAGE_H

namespace Bubblewrap
{
	namespace Base
	{
		class EvtMessage
		{
		public:
			EvtMessage();
			EvtMessage( int Type );
			EvtMessage( int Type, void* Data );
			int Type_;
			void* Data_;
		};
	}
}



#endif