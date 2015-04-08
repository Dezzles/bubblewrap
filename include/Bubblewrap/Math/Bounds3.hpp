#ifndef BUBBLEWRAP_BOUNDS3_HPP
#define BUBBLEWRAP_BOUNDS3_HPP

#include "Bubblewrap/Math/Bounds1.hpp"
#include "Bubblewrap/Math/Vector3.hpp"
namespace Bubblewrap
{
	namespace Math
	{
		template < typename T_ >
		/*! Object designed for the defining of three dimensional ranges */
		class Bounds3
		{
		private:
			Bounds1< T_ > BoundsD1;
			Bounds1< T_ > BoundsD2;
			Bounds1< T_ > BoundsD3;

		public:
			/*! Creates bounds with ranges of ( 0.0 - 0.0, 0.0 - 0.0, 0.0 - 0.0 ) */
			Bounds3()
			{

			}

			/*! Creates a new three dimensional bounds. This will automatically place the bounds
			in lower to upper order.
			\param D1Lower The lower bound of the first dimension
			\param D1Upper The upper bound of the first dimension
			\param D2Lower The lower bound of the second dimension
			\param D2Upper The upper bound of the second dimension
			\param D3Lower The lower bound of the second dimension
			\param D3Upper The upper bound of the second dimension
			*/
			Bounds3( T_ D1Lower, T_ D1Upper, T_ D2Lower, T_ D2Upper, T_ D3Lower, T_ D3Upper )
				: BoundsD1( D1Lower, D1Upper ), BoundsD2( D2Lower, D2Upper ), BoundsD3( D3Lower, D3Upper )
			{
			}

			/*! Creates a new three dimensional bounds. This will automatically place the bounds
			in lower to upper order.
			\param Lower A Vector3 representing the lower bounds
			\param Upper A Vector3 representing the upper bounds
			*/
			Bounds3( Vector3<T_> Lower, Vector3<T_> Upper )
				: BoundsD1( Lower.X(), Upper.X() ), BoundsD2( Lower.Y(), Upper.Y() ), BoundsD3( Lower.Z(), Upper.Z() )
			{
			}

			/*! Gets the range of the bounds
			\returns A Vector3 representing the range of the bounds
			*/
			Vector3<T_> Range()
			{
				return Vector3<T_>( BoundsD1.Range(), BoundsD2.Range, BoundsD3.Range );
			}

			/*! Gets the Lower bounds
			\returns A Vector3 representing the lower bounds
			*/
			Vector3<T_> Lower()
			{
				return Vector3<T_>( BoundsD1.Lower(), BoundsD2.Lower(), BoundsD3.Lower() );
			}

			/*! Gets the Upper bounds
			\returns A Vector3 representing the upper bounds
			*/
			Vector3<T_> Upper()
			{
				return Vector3<T_>( BoundsD1.Upper(), BoundsD2.Upper(), BoundsD3.Upper() );
			}

			/*! Restricts a value to be inside the current bounds
			\param Val The Vector2 that needs to be restricted
			\returns A Vector2 where each component will be restricted to its dimensional bounds
			*/
			Vector3<T_> Restrict( Vector3<T_> Val )
			{
				return Vector3<T_>( BoundsD1.Restrict( Val.X() ), BoundsD2.Restrict( Val.Y() ), BoundsD3.Restrict( Val.Z() ) );
			}

			/*! Restricts a value to be inside the current bounds
			\param D1Val Value to be restricted against first dimension
			\param D2Val Value to be restricted against second dimension
			\param D3Val Value to be restricted against second dimension
			\returns A Vector3 where each dimension will be restricted to its dimensional bounds
			*/
			Vector3<T_> Restrict( float D1Val, float D2Val, float D3Val )
			{
				return Vector2<T_>( BoundsD1.Restrict( D1Val ), BoundsD2.Restrict( D2Val ), BoundsD3.Restrict( D3Val ) );
			}

			/*! Checks whether a value is inside the bounds or not
			\param Val The value being tested
			\returns True if the value is greater than or equal to Lower and less than or equal to Upper
			*/
			bool Inside( Vector3<T_> Val )
			{
				return ( BoundsD1.Inside( Val.X() ) && BoundsD2.Inside( Val.Y() ) && BoundsD3.Inside( Val.Y() ) );
			}

			/*! Checks whether a value is inside the bounds or not
			\param D1Val The value being tested for the first dimension
			\param D2Val The value being tested for the second dimension
			\param D3Val The value being tested for the third dimension
			\returns True if the value is greater than or equal to Lower and less than or equal to Upper
			*/
			bool Inside( T_ D1Val, T_ D2Val, T_ D3Val )
			{
				return ( BoundsD1.Inside( D1Val ) && BoundsD2.Inside( D2Val ) && BoundsD3.Inside( D3Val ) );
			}

			/*! Shrinks the size of the bounds. Bounds will be shrunk evenly from both ends. If Val is greater than the
			range of the bounds, both Upper and Lower will meet at the midpoint.
			\param D1Val The amount that the first dimension bounds should be shrunk.
			\param D2Val The amount that the second dimension bounds should be shrunk.
			\param D3Val The amount that the third dimension bounds should be shrunk.
			*/
			void ShrinkBounds( T_ D1Val, T_ D2Val, T_ D3Val )
			{
				BoundsD1.ShrinkBounds( D1Val );
				BoundsD2.ShrinkBounds( D2Val );
				BoundsD3.ShrinkBounds( D3Val );
			}

			/*! Shrinks the size of the bounds. Bounds will be shrunk evenly from both ends. If Val is greater than the
			range of the bounds, both Upper and Lower will meet at the midpoint.
			\param Val The amount that the bounds should be shrunk.
			*/
			void ShrinkBounds( Vector3<T_> Val )
			{
				BoundsD1.ShrinkBounds( Val.X() );
				BoundsD2.ShrinkBounds( Val.Y() );
				BoundsD3.ShrinkBounds( Val.Z() );
			}

			/*! Shrinks the size of the bounds. Lower value will be increased. If Val is greater than the
			range of the bounds, Lower will equal Upper.
			\param D1Val The amount that the first dimension bounds should be shrunk.
			\param D2Val The amount that the second dimension bounds should be shrunk.
			\param D3Val The amount that the third dimension bounds should be shrunk.
			*/
			void ShrinkLower( T_ D1Val, T_ D2Val, T_ D3Val )
			{
				BoundsD1.ShrinkLower( D1Val );
				BoundsD2.ShrinkLower( D2Val );
				BoundsD3.ShrinkLower( D3Val );
			}

			/*! Shrinks the size of the bounds. Lower value will be increased. If Val is greater than the
			range of the bounds, Lower will equal Upper.
			\param Val The amount that the bounds should be shrunk.
			*/
			void ShrinkLower( Vector3<T_> Val )
			{
				BoundsD1.ShrinkLower( Val.X() );
				BoundsD2.ShrinkLower( Val.Y() );
				BoundsD3.ShrinkLower( Val.Z() );
			}

			/*! Shrinks the size of the bounds. Upper value will be increased. If Val is greater than the
			range of the bounds, Upper will equal Lower.
			\param D1Val The amount that the first dimension bounds should be shrunk.
			\param D2Val The amount that the second dimension bounds should be shrunk.
			\param D3Val The amount that the third dimension bounds should be shrunk.
			*/
			void ShrinkUpper( T_ D1Val, T_ D2Val, T_ D3Val )
			{
				BoundsD1.ShrinkUpper( D1Val );
				BoundsD2.ShrinkUpper( D2Val );
				BoundsD3.ShrinkUpper( D3Val );
			}

			/*! Shrinks the size of the bounds. Upper value will be increased. If Val is greater than the
			range of the bounds, Upper will equal Lower.
			\param Val The amount that the bounds should be shrunk.
			*/
			void ShrinkUpper( Vector3<T_> Val )
			{
				BoundsD1.ShrinkUpper( Val.X() );
				BoundsD2.ShrinkUpper( Val.Y() );
				BoundsD3.ShrinkUpper( Val.Z() );
			}

			/*! Increases the size of the bounds. Bounds will grow evenly
			\param D1Val The amount that the first dimension bounds should be grown.
			\param D2Val The amount that the second dimension bounds should be grown.
			\param D3Val The amount that the third dimension bounds should be grown.
			*/
			void GrowBounds( T_ D1Val, T_ D2Val, T_ D3Val )
			{
				BoundsD1.GrowBounds( D1Val );
				BoundsD2.GrowBounds( D2Val );
				BoundsD3.GrowBounds( D3Val );
			}

			/*! Increases the size of the bounds. Bounds will grow evenly
			\param Val The amount that the bounds should be grown.
			*/
			void GrowBounds( Vector3<T_> Val )
			{
				BoundsD1.GrowBounds( Val.X() );
				BoundsD2.GrowBounds( Val.Y() );
				BoundsD3.GrowBounds( Val.Z() );
			}

			/*! Increases the size of the bounds. Bounds will be grow from Lower.
			\param D1Val The amount that the first dimension bounds should be grown.
			\param D2Val The amount that the second dimension bounds should be grown.
			\param D3Val The amount that the third dimension bounds should be grown.
			*/
			void GrowLower( T_ D1Val, T_ D2Val, T_ D3Val )
			{
				BoundsD1.GrowLower( D1Val );
				BoundsD2.GrowLower( D2Val );
				BoundsD3.GrowLower( D3Val );
			}

			/*! Increases the size of the bounds. Bounds will be grow from Lower.
			\param Val The amount that the bounds should be grown.
			*/
			void GrowLower( Vector3<T_> Val )
			{
				BoundsD1.GrowLower( Val.X() );
				BoundsD2.GrowLower( Val.Y() );
				BoundsD3.GrowLower( Val.Z() );
			}

			/*! Increases the size of the bounds. Bounds will be grow from Upper.
			\param D1Val The amount that the first dimension bounds should be grown.
			\param D2Val The amount that the second bounds should be grown.
			\param D3Val The amount that the third bounds should be grown.
			*/
			void GrowUpper( T_ D1Val, T_ D2Val, T_ D3Val )
			{
				BoundsD1.GrowUpper( D1Val );
				BoundsD2.GrowUpper( D2Val );
				BoundsD3.GrowUpper( D3Val );
			}

			/*! Increases the size of the bounds. Bounds will be grow from Upper.
			\param Val The amount that the bounds should be grown.
			*/
			void GrowUpper( Vector3<T_> Val )
			{
				BoundsD1.GrowUpper( Val.X() );
				BoundsD2.GrowUpper( Val.Y() );
				BoundsD3.GrowUpper( Val.Z() );
			}


		};

		typedef Bounds3<float> Bounds3f;
		typedef Bounds3<int> Bounds3i;
		typedef Bounds3<double> Bounds3d;
	}
}



#endif