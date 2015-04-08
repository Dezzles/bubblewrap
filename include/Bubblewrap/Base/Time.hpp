#ifndef TIME_HPP
#define TIME_HPP

namespace Bubblewrap
{
	namespace Base
	{
		/*! Measures time spans*/
		class Time
		{
		public:
			/*! Initialises a Time 
			\param dt The time span being measured in seconds 
			*/
			Time(float dt);
			/*! Gets the current time
			\returns The current time in seconds 
			*/
			float AsSeconds();

		private:
			float ElapsedTime_;
		};

	}
}


#endif