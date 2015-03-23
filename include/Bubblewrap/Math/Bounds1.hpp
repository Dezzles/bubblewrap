#ifndef BUBBLEWRAP_BOUNDS1_HPP
#define BUBBLEWRAP_BOUNDS1_HPP

namespace Bubblewrap
{
	namespace Math
	{
		template < typename T_ >
		class Bounds1
		{
		private:
			T_ Min_;
			T_ Max_;

		public:
			Bounds1( T_ Min, T_ Max )
				: Min_( Min ), Max_( Max )
			{
				if ( Max < Min )
				{
					Max_ = Min;
					Min_ = Max;
				}
			}

			T_ Range()
			{
				return Max_ - Min;
			}

			T_ Min()
			{
				return Min_;
			}

			T_ Max()
			{
				return Max_;
			}

			T_ Restrict( T_ Val )
			{
				return ( Val < Min_ ? Min_ : ( Val > Max_ ? Max_ : Val ) );
			}
		};

		typedef Bounds1<float> Bounds1f;
		typedef Bounds1<int> Bounds1i;
		typedef Bounds1<double> Bounds1d;
	}
}



#endif