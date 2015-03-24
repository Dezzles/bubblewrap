#ifndef BUBBLEWRAP_BOUNDS3_HPP
#define BUBBLEWRAP_BOUNDS3_HPP

#include "Bubblewrap/Math/Bounds1.hpp"
#include "Bubblewrap/Math/Vector3.hpp"
namespace Bubblewrap
{
	namespace Math
	{
		template < typename T_ >
		class Bounds3
		{
		private:
			Bounds1< T_ > BoundsD1;
			Bounds1< T_ > BoundsD2;
			Bounds1< T_ > BoundsD3;

		public:
			Bounds3( T_ D1Lower, T_ D1Upper, T_ D2Lower, T_ D2Upper, T_ D3Lower, T_ D3Upper )
				: BoundsD1( D1Lower, D1Upper ), BoundsD2( D2Lower, D2Upper ), BoundsD3( D3Lower, D3Upper )
			{
			}
			Bounds3( Vector3<T_> Lower, Vector3<T_> Upper )
				: BoundsD1( Lower.X(), Upper.X() ), BoundsD2( Lower.Y(), Upper.Y() ), BoundsD3( Lower.Z(), Upper.Z() )
			{
			}

			Vector3<T_> Range()
			{
				return Vector3<T_>( BoundsD1.Range(), BoundsD2.Range, BoundsD3.Range );
			}

			Vector3<T_> Lower()
			{
				return Vector3<T_>( BoundsD1.Lower(), BoundsD2.Lower(), BoundsD3.Lower() );
			}

			Vector3<T_> Upper()
			{
				return Vector3<T_>( BoundsD1.Upper(), BoundsD2.Upper(), BoundsD3.Upper() );
			}

			Vector3<T_> Restrict( Vector3<T_> Val )
			{
				return Vector3<T_>( BoundsD1.Restrict( Val.X() ), BoundsD2.Restrict( Val.Y() ), BoundsD3.Restrict( Val.Z() ) );
			}
		};

		typedef Bounds3<float> Bounds3f;
		typedef Bounds3<int> Bounds3i;
		typedef Bounds3<double> Bounds3d;
	}
}



#endif