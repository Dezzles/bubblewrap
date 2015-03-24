#ifndef BUBBLEWRAP_BOUNDS2_HPP
#define BUBBLEWRAP_BOUNDS2_HPP

#include "Bubblewrap/Math/Bounds1.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
namespace Bubblewrap
{
	namespace Math
	{
		template < typename T_ >
		class Bounds2
		{
		private:
			Bounds1< T_ > BoundsD1;
			Bounds1< T_ > BoundsD2;

		public:
			Bounds2( T_ D1Lower, T_ D1Upper, T_ D2Lower, T_ D2Upper )
				: BoundsD1( D1Lower, D1Upper ), BoundsD2( D2Lower, D2Upper )
			{
			}
			Bounds2( Vector2<T_> Lower, Vector2<T_> Upper )
				: BoundsD1( Lower.X(), Upper.X() ), BoundsD2( Lower.Y(), Upper.Y() )
			{
			}

			Vector2<T_> Range()
			{
				return Vector2<T_>( BoundsD1.Range(), BoundsD2.Range );
			}

			Vector2<T_> Lower()
			{
				return Vector2<T_>( BoundsD1.Lower(), BoundsD2.Lower() );
			}

			Vector2<T_> Upper()
			{
				return Vector2<T_>( BoundsD1.Upper(), BoundsD2.Upper() );
			}

			Vector2<T_> Restrict( Vector2<T_> Val )
			{
				return Vector2<T_>( BoundsD1.Restrict( Val.X() ), BoundsD2.Restrict( Val.Y() ) );
			}

			
		};

		typedef Bounds2<float> Bounds2f;
		typedef Bounds2<int> Bounds2i;
		typedef Bounds2<double> Bounds2d;
	}
}



#endif