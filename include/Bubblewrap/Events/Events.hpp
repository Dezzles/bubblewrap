#ifndef BUBBLEWRAP_EVENT_EVENTS_HPP
#define BUBBLEWRAP_EVENT_EVENTS_HPP

#include "Bubblewrap/Events/Event.hpp"
#include "Bubblewrap/Events/EventKeyInput.hpp"
namespace Bubblewrap
{
	namespace Events
	{
		/*! Storage class for data related to input events.
		*/
		class InputData
			: public EventData
		{
		public:
			/*! The type of input event that is being sent 
			*/
			enum class InputType
			{
				KeyDown,
				KeyUp
			};

			/*! The input type of this event */
			InputType InputType_;
			/*! The key code for this event */
			Key Key_;
			/*! Indicates whether the Alt key is down */
			bool Alt_;
			/*! Indicates whether the Shift key is down */
			bool Shift_;
			/*! Indicates whether the Control key is down */
			bool Control_;
		};
	}
}

#endif