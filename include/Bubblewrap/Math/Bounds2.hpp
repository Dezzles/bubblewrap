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
			Bounds2( T_ D1Min, T_ D1Max, T_ D2Min, T_ D2Max )
				: BoundsD1( D1Min, D1Max ), BoundsD2( D2Min, D2Max )
			{
			}
			Bounds2( Vector2<T_> Min, Vector2<T_> Max )
				: BoundsD1( Min.X(), Max.X() ), BoundsD2( Min.Y(), Max.Y() )
			{
			}

			Vector2<T_> Range()
			{
				return Vector2<T_>( BoundsD1.Range(), BoundsD2.Range );
			}

			Vector2<T_> Min()
			{
				return Vector2<T_>( BoundsD1.Min(), BoundsD2.Min() );
			}

			Vector2<T_> Max()
			{
				return Vector2<T_>( BoundsD1.Max(), BoundsD2.Max() );
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