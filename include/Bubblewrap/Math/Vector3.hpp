#ifndef MAVECTOR3_HPP
#define MAVECTOR3_HPP

#include <math.h>
#include <string>
#include "Bubblewrap/Math/Vector2.hpp"

namespace Bubblewrap
{
	namespace Math
	{
		template < typename T_ >
		class Vector3
		{
		private:
			T_ X_;
			T_ Y_;
			T_ Z_;


		public:
			Vector3()
				: X_( 0 ), Y_( 0 ), Z_( 0 )
			{
			}
			Vector3( T_ X, T_ Y, T_ Z )
				: X_( X ), Y_( Y ), Z_( Z )
			{

			}

			Vector3( std::string Vec )
			{
				int Idx1 = Vec.find_first_of( ' ' );
				int Idx2 = Vec.find_first_of( ' ',  Idx1 + 1 );
					
				std::string sX = Vec.substr( 0, Idx1 );
				std::string sY = Vec.substr( Idx1 + 1, Idx2 - Idx1 );
				std::string sZ = Vec.substr( Idx2 + 1 );

				
				X_ = ( T_ ) atof( sX.c_str() );
				Y_ = ( T_ ) atof( sY.c_str() );
				Z_ = ( T_ ) atof( sZ.c_str() );
			}

			T_ X() const
			{
				return X_;
			}

			T_ Y() const
			{
				return Y_;
			}

			T_ Z() const
			{
				return Z_;
			}

			void SetX( T_ X )
			{
				X_ = X;
			}

			void SetY( T_ Y )
			{
				Y_ = Y;
			}

			void SetZ( T_ Z )
			{
				Z_ = Z;
			}

			T_ Length()
			{
				return ( T_ ) ( sqrt( X_ * X_ + Y_ * Y_ + Z_ * Z_ ) );
			}

			Vector3 Normalised()
			{
				T_ mul = 1.0f / Length();
				return Vector3( X_ * mul, Y_ * mul, Z_ * mul );
			}

			Vector3 operator==( Vector3& Other )
			{
				return ( ( X_ == Other.X_ ) && ( Y_ == Other.Y_ ) && ( Z_ == Other.Z_ ) );
			}

			Vector3 operator+( const Vector3& Other )
			{
				return Vector3( X_ + Other.X_, Y_ + Other.Y_, Z_ + Other.Z_ );
			}

			Vector3 operator-( const Vector3& Other )
			{
				return Vector3( X_ - Other.X_, Y_ - Other.Y_, Z_ - Other.Z_ );
			}

			Vector3 operator-( )
			{
				return Vector3( -X_, -Y_, -Z_ );
			}

			Vector3 operator+( )
			{
				return Vector3( X_, Y_, Z_ );
			}

			Vector3 operator*( const float M )
			{
				return Vector3( X_ * M, Y_ * M, Z_ * M );
			}

			Vector3 operator/( const float M )
			{
				return Vector3( X_ / M, Y_ / M, Z_ / M );
			}

			T_& operator[]( int N )
			{
				assert( N >= 0 && N <= 2 );
				if ( 0 == N )
					return X_;
				if ( 1 == N )
					return Y_;
				else
					return Z_;
			}

			Vector3 operator+=( const Vector3 &RHS )
			{
				return Vector3( X_ + RHS.X_, Y_ + RHS.Y_, Z_ + RHS.Z_s );
			}

			Vector3 operator-=( const Vector3 &RHS )
			{
				return Vector3( X_ - RHS.X_, Y_ - RHS.Y_, Z_ - RHS.Z_ );
			}

			Vector3 operator*=( const float &RHS )
			{
				return Vector3( X_ * RHS, Y_ * RHS, Z_ * RHS );
			}

			Vector3 operator/=( const float &RHS )
			{
				return Vector3( X_ / RHS, Y_ / RHS, Z_ / RHS );
			}

			Vector2<T_> XY()
			{
				return Vector2<T_>( X_, Y_ );
			}

			Vector2<T_> XZ()
			{
				return Vector2<T_>( X_, Z_ );
			}

			Vector2<T_> YZ()
			{
				return Vector2<T_>( Y_, Z_ );
			}
		};
		template< typename T_ >
		Vector3<T_> operator*( T_ LHS, const Vector3<T_> V ) 
		{
			return Vector3<T_>( LHS * V.X(), LHS * V.Y(), LHS * V.Z() );
		}

		typedef Vector3<float> Vector3f;
		typedef Vector3<double> Vector3d;
		typedef Vector3<int> Vector3i;
	}
}
#endif