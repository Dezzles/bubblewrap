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
			Bounds3( T_ D1Min, T_ D1Max, T_ D2Min, T_ D2Max, T_ D3Min, T_ D3Max )
				: BoundsD1( D1Min, D1Max ), BoundsD2( D2Min, D2Max ), BoundsD3( D3Min, D3Max )
			{
			}
			Bounds3( Vector3<T_> Min, Vector3<T_> Max )
				: BoundsD1( Min.X(), Max.X() ), BoundsD2( Min.Y(), Max.Y() ), BoundsD3( Min.Z(), Max.Z() )
			{
			}

			Vector3<T_> Range()
			{
				return Vector3<T_>( BoundsD1.Range(), BoundsD2.Range, BoundsD3.Range );
			}

			Vector3<T_> Min()
			{
				return Vector3<T_>( BoundsD1.Min(), BoundsD2.Min(), BoundsD3.Min() );
			}

			Vector3<T_> Max()
			{
				return Vector3<T_>( BoundsD1.Max(), BoundsD2.Max(), BoundsD3.Max() );
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