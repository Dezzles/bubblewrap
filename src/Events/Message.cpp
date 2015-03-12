#include "Bubblewrap/Events/Message.hpp"

namespace Bubblewrap
{
	namespace Events
	{
		Message::Message( int MessageType, MessageData* Data )
		{
			MessageType_ = MessageType;
		}


		int Message::GetMessageType() const
		{
			return MessageType_;
		}

		MessageData* Message::GetData() const
		{
			return Data_;
		}

	}
}