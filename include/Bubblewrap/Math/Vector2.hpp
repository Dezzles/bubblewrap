#ifndef MAVECTOR2_H
#define MAVECTOR2_H

#include <math.h>
#include <string>
namespace Bubblewrap
{
	namespace Math
	{
		template < typename T_ >
		class Vector2
		{
		private:
			T_ X_;
			T_ Y_;


		public:
			Vector2()
				: X_( 0 ), Y_( 0 )
			{
			}
			Vector2( T_ X, T_ Y )
				: X_( X ), Y_( Y )
			{

			}

			Vector2( std::string Vec )
			{
				int Idx1 = Vec.find_first_of( ' ' );
					
				std::string sX = Vec.substr( 0, Idx1 );
				std::string sY = Vec.substr( Idx1 + 1 );

				
				X_ = (T_)atof( sX.c_str() );
				Y_ = (T_)atof( sY.c_str() );

			}

			T_ X() const
			{
				return X_;
			}

			T_ Y() const
			{
				return Y_;
			}

			static Vector2 FromPolarCoords( T_ Theta, T_ Radius )
			{
				return Vector2( cosf( Theta ) * Radius, sinf( Theta ) * Radius );
			}

			Vector2 operator==( Vector2& Other )
			{
				return ( ( X_ == Other.X_ ) && ( Y_ == Other.Y_ ) );
			}

			Vector2 operator+( const Vector2& Other )
			{
				return Vector2( X_ + Other.X_, Y_ + Other.Y_ );
			}

			Vector2 operator-( const Vector2& Other )
			{
				return Vector2( X_ - Other.X_, Y_ - Other.Y_ );
			}

			Vector2 operator-( )
			{
				return Vector2( -X_, -Y_ );
			}

			Vector2 operator+( )
			{
				return Vector2( X_, Y_ );
			}

			Vector2 operator*( const float M )
			{
				return Vector2( X_ * M, Y_ * M );
			}

			Vector2 operator/( const float M )
			{
				return Vector2( X_ / M, Y_ / M );
			}

			T_& operator[]( int N )
			{
				assert( N >= 0 && N <= 1 );
				if ( 0 == N )
					return X_;
				else
					return Y_;
			}

			Vector2 operator+=( const Vector2 &RHS )
			{
				return Vector2( X_ + RHS.X_, Y_ + RHS.Y_ );
			}

			Vector2 operator-=( const Vector2 &RHS )
			{
				return Vector2( X_ - RHS.X_, Y_ - RHS.Y_ );
			}

			Vector2 operator*=( const float &RHS )
			{
				return Vector2( X_ * RHS, Y_ * RHS );
			}

			Vector2 operator/=( const float &RHS )
			{
				return Vector2( X_ / RHS, Y_ / RHS );
			}
		};
		template< typename T_ >
		Vector2<T_> operator*( T_ LHS, const Vector2<T_> V ) 
		{
			return Vector2<T_>( LHS * V.X(), LHS * V.Y() );
		}

		typedef Vector2<float> Vector2f;
		typedef Vector2<double> Vector2d;
		typedef Vector2<int> Vector2i;
	}
}
#endif