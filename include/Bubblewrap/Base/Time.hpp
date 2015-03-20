#ifndef TIME_HPP
#define TIME_HPP

namespace Bubblewrap
{
	namespace Base
	{
		class Time
		{
		public:
			Time(float dt);
			float AsSeconds();

		private:
			float ElapsedTime_;
		};

	}
}


#endif