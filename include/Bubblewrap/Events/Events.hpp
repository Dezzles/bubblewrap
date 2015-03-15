#ifndef MESSAGES_HPP
#define MESSAGES_HPP

#include "Bubblewrap/Events/Event.hpp"
#include "Bubblewrap/Events/EventKeyInput.hpp"
namespace Bubblewrap
{
	namespace Events
	{
		class InputData
			: public EventData
		{
		public:
			enum class InputType
			{
				KeyDown,
				KeyUp
			};

			InputType InputType_;
			Key Key_;
			bool Alt_;
			bool Shift_;
			bool Control_;
		};
	}
}

#endif