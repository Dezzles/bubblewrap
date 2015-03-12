#ifndef MESSAGES_HPP
#define MESSAGES_HPP

#include "Message.hpp"

namespace Bubblewrap
{
	namespace Events
	{
		namespace MessageTypes
		{
			enum MessageTypes : unsigned int
			{
				Input
			};
		}

		class InputMessage
			: MessageData
		{
			enum InputType
			{
				KeyDown,
				KeyUp
			};

			InputType InputType_;
		};
	}
}

#endif