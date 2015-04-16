#ifndef BUBBLEWRAP_MATH_VECTOR2_HPP
#define BUBBLEWRAP_MATH_VECTOR2_HPP

#include <math.h>
#include <string>
#include "Bubblewrap/Base/Assert.hpp" 
namespace Bubblewrap
{
	namespace Math
	{
		template < typename T_ >
		class Matrix3;
		/*! A two dimensional Vector template
		*/
		template < typename T_ >
		class Vector2
		{
			friend Matrix3< T_ >;
		private:
			T_ X_;
			T_ Y_;


		public:
			/*! Creates a Vector2 with default coordinates */
			Vector2()
				: X_( 0 ), Y_( 0 )
			{
			}
			/*! Creates a Vector2
			\param X The X coordinate
			\param Y The Y coordinate
			*/
			Vector2( T_ X, T_ Y )
				: X_( X ), Y_( Y )
			{

			}

			/*! Creates a vector using coordinates stored in string format. 
			\param Vec A string in the format "0.0 0.0"
			*/
			Vector2( std::string Vec )
			{
				int Idx1 = Vec.find_first_of( ' ' );
					
				std::string sX = Vec.substr( 0, Idx1 );
				std::string sY = Vec.substr( Idx1 + 1 );

				
				X_ = (T_)atof( sX.c_str() );
				Y_ = (T_)atof( sY.c_str() );
			}

			/*! Gets the X coordinate of the Vector2 
			\returns X coordinate 
			*/
			T_ X() const
			{
				return X_;
			}

			/*! Gets the Y coordinate of the Vector2
			\returns Y coordinate
			*/
			T_ Y() const
			{
				return Y_;
			}

			/*! Sets the X coordinate of the Vector2 
			\param X The new X coordinate
			*/
			void SetX( float X )
			{
				X_ = X;
			}

			/*! Sets the Y coordinate of the Vector2
			\param Y The new Y coordinate
			*/
			void SetY( float Y )
			{
				Y_ = Y;
			}

			/*! Creates a new Vector2 from polar coordinates.
			\param Theta The vector's angle from the X axis
			\param Radius The magnitude of the vector
			\returns A new Vector2 based on the angle and radius
			*/
			static Vector2 FromPolarCoords( T_ Theta, T_ Radius )
			{
				return Vector2( cosf( Theta ) * Radius, sinf( Theta ) * Radius );
			}

			/*! Compares two vectors
			\param Other The vector being compared to
			\returns True if the X and Y values of both vectors are identical.
			*/
			bool operator==( Vector2& Other )
			{
				return ( ( X_ == Other.X_ ) && ( Y_ == Other.Y_ ) );
			}

			/*! Adds two vectors
			\param Other The vector being added
			\returns A new vector which is the addition of this vector and Other
			*/
			Vector2 operator+( const Vector2& Other )
			{
				return Vector2( X_ + Other.X_, Y_ + Other.Y_ );
			}

			/*! Subtracts another vector from this one
			\param Other The vector being subtracted
			\returns A new vector which is the result of Other being subtracted from this vector
			*/
			Vector2 operator-( const Vector2& Other )
			{
				return Vector2( X_ - Other.X_, Y_ - Other.Y_ );
			}

			/*! Creates the negative of a vector
			\returns The negative of this vector
			*/
			Vector2 operator-( )
			{
				return Vector2( -X_, -Y_ );
			}

			/*! Creates this vector effectively
			\returns A new vector with the same values as the current vector
			*/
			Vector2 operator+( )
			{
				return Vector2( X_, Y_ );
			}

			/*! Multiplies a vector by a scalar value
			\param M A scalar value the vector should be multiplied by
			\returns A New vector where the components are multipied by M
			*/
			Vector2 operator*( const T_ M )
			{
				return Vector2( X_ * M, Y_ * M );
			}

			/*! Divides the vector by a scalar value
			\param M The scalar value the vector will be divided by
			\returns A new vector where the components are divided by M
			*/
			Vector2 operator/( const T_ M )
			{
				return Vector2( X_ / M, Y_ / M );
			}

			/*! Gets individiual components of the vector by index
			\param Idx The index of the component
			\return The value of the component
			*/
			T_& operator[]( int Idx )
			{
				AssertMessage( Idx >= 0 && Idx <= 1, "Index out of bounds" );
				if ( 0 == Idx )
					return X_;
				else
					return Y_;
			}

			/*! Adds a vector to the current vector 
			\param RHS The vector to add to the current vector
			\returns The two vectors added together
			*/
			Vector2& operator+=( const Vector2 &RHS )
			{
				X_ += RHS.X_;
				Y_ += RHS.Y_;
				return *this;
			}

			/*! Subtracts a vector from the current vector
			\param RHS The vector to be subtracted from the current vector
			\returns The current vector with RHS subtracted from it
			*/
			Vector2& operator-=( const Vector2 &RHS )
			{
				X_ -= RHS.X_;
				Y_ -= RHS.Y_;
				return *this;
			}

			/*! The current vector multiplied by a scalar
			\param RHS The scalar the vector should be multiplied by
			\returns The vector multiplied by the scalr
			*/
			Vector2& operator*=( const T_ &RHS )
			{
				X_ *= RHS;
				Y_ *= RHS;
				return *this;

			}

			/*! The current vector divided by a scalar
			\param RHS The scalar the vector should be divided by
			\returns The vector divided by the scalr
			*/
			Vector2& operator/=( const T_ &RHS )
			{
				X_ /= RHS;
				Y_ /= RHS;
				return *this;
			}

			/*! Gets the length of a vector
			\returns The length of the vector
			*/
			T_ Length()
			{
				return ( T_ ) ( sqrt( X_ * X_ + Y_ * Y_ ) );
			}

			/*! Gets the normalised version a vector.
			\returns A normalised version of the vector. 
			*/
			Vector2 Normalised()
			{
				T_ mul = 1.0f / Length();
				return Vector2( X_ * mul, Y_ * mul );
			}
		};
		/*! Multiplies a scalar by a vector
		\param LHS The scalar that is being multiplied
		\param V The vector that the scalar is being multiplied by
		\returns A vector multiplied by the scalar
		*/
		template< typename T_ >
		Vector2<T_> operator*( const T_ LHS, const Vector2<T_> V ) 
		{
			return Vector2<T_>( LHS * V.X(), LHS * V.Y() );
		}

		typedef Vector2<float> Vector2f;
		typedef Vector2<double> Vector2d;
		typedef Vector2<int> Vector2i;
	}
}
#endif
