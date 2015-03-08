#include "Bubblewrap/Base/EvtMessage.hpp"


namespace Bubblewrap
{
	namespace Base
	{
		EvtMessage::EvtMessage()
		{

		}
		EvtMessage::EvtMessage( int Type )
		{
			Type_ = Type;
		}
		EvtMessage::EvtMessage( int Type, void* Data )
		{
			Type_ = Type;
			Data_ = Data;
			
		}
	}
}