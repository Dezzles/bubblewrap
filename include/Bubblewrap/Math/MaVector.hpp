#ifndef MAVECTOR_H
#define MAVECTOR_H

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

			T_ X() const
			{
				return X_;
			}

			T_ Y() const
			{
				return Y_;
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