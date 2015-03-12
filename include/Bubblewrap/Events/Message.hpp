#ifndef EVMESSAGE_HPP
#define EVMESSAGE_HPP

namespace Bubblewrap
{
	namespace Events
	{
		class Manager;
		class MessageData
		{ };

		class Message
		{
			friend Manager;
		public:
			Message( int MessageType, MessageData* Data );


			int GetMessageType() const;
			MessageData* GetData() const;
		private:
			int MessageType_;
			MessageData* Data_;

			Message( const Message& Other )
			{
			}
		};
	}
}


#endif