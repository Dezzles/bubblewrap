#ifndef BUBBLEWRAP_MATH_VECTOR3_HPP
#define BUBBLEWRAP_MATH_VECTOR3_HPP

#include <math.h>
#include <string>
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Base/Assert.hpp"
namespace Bubblewrap
{
	namespace Math
	{
		/*! A three dimensional Vector template
		*/
		template < typename T_ >
		class Vector3
		{
		private:
			T_ X_;
			T_ Y_;
			T_ Z_;


		public:
			/*! Creates a vector with default coordinates */
			Vector3()
				: X_( 0 ), Y_( 0 ), Z_( 0 )
			{
			}
			/*! Creates a vector
			\param X The X coordinate
			\param Y The Y coordinate
			\param Z The Z coordinate
			*/
			Vector3( T_ X, T_ Y, T_ Z )
				: X_( X ), Y_( Y ), Z_( Z )
			{

			}

			/*! Creates a vector using coordinates stored in string format.
			\param Vec A string in the format "0.0 0.0 0.0"
			*/
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

			/*! Gets the X coordinate of the vector
			\returns X coordinate
			*/
			T_ X() const
			{
				return X_;
			}

			/*! Gets the Y coordinate of the vector
			\returns Y coordinate
			*/
			T_ Y() const
			{
				return Y_;
			}

			/*! Gets the Z coordinate of the vector
			\returns Z coordinate
			*/
			T_ Z() const
			{
				return Z_;
			}

			/*! Sets the X coordinate of the vector
			\param X The new X coordinate
			*/
			void SetX( T_ X )
			{
				X_ = X;
			}

			/*! Sets the Y coordinate of the vector
			\param Y The new Y coordinate
			*/
			void SetY( T_ Y )
			{
				Y_ = Y;
			}

			/*! Sets the Z coordinate of the vector
			\param Z The new Z coordinate
			*/
			void SetZ( T_ Z )
			{
				Z_ = Z;
			}

			/*! Gets the length of a vector
			\returns The length of the vector
			*/
			T_ Length()
			{
				return ( T_ ) ( sqrt( X_ * X_ + Y_ * Y_ + Z_ * Z_ ) );
			}

			/*! Gets the normalised version a vector.
			\returns A normalised version of the vector.
			*/
			Vector3 Normalised()
			{
				T_ mul = 1.0f / Length();
				return Vector3( X_ * mul, Y_ * mul, Z_ * mul );
			}

			/*! Compares two vectors
			\param Other The vector being compared to
			\returns True if the X, Y and Z values of both vectors are identical.
			*/
			Vector3 operator==( Vector3& Other )
			{
				return ( ( X_ == Other.X_ ) && ( Y_ == Other.Y_ ) && ( Z_ == Other.Z_ ) );
			}

			/*! Adds two vectors
			\param Other The vector being added
			\returns A new vector which is the addition of this vector and Other
			*/
			Vector3 operator+( const Vector3& Other )
			{
				return Vector3( X_ + Other.X_, Y_ + Other.Y_, Z_ + Other.Z_ );
			}

			/*! Subtracts another vector from this one
			\param Other The vector being subtracted
			\returns A new vector which is the result of Other being subtracted from this vector
			*/
			Vector3 operator-( const Vector3& Other )
			{
				return Vector3( X_ - Other.X_, Y_ - Other.Y_, Z_ - Other.Z_ );
			}

			/*! Creates the negative of a vector
			\returns The negative of this vector
			*/
			Vector3 operator-( )
			{
				return Vector3( -X_, -Y_, -Z_ );
			}

			/*! Creates this vector effectively
			\returns A new vector with the same values as the current vector
			*/
			Vector3 operator+( )
			{
				return Vector3( X_, Y_, Z_ );
			}

			/*! Multiplies a vector by a scalar value
			\param M A scalar value the vector should be multiplied by
			\returns A New vector where the components are multipied by M
			*/
			Vector3 operator*( const T_ M )
			{
				return Vector3( X_ * M, Y_ * M, Z_ * M );
			}

			/*! Divides the vector by a scalar value
			\param M The scalar value the vector will be divided by
			\returns A new vector where the components are divided by M
			*/
			Vector3 operator/( const T_ M )
			{
				return Vector3( X_ / M, Y_ / M, Z_ / M );
			} 

			/*! Gets individiual components of the vector by index
			\param Idx The index of the component
			\return The value of the component
			*/
			T_& operator[]( int Idx )
			{
				AssertMessage( Idx >= 0 && Idx <= 2, "Index out of bounds" );
				if ( 0 == Idx )
					return X_;
				if ( 1 == Idx )
					return Y_;
				else
					return Z_;
			}

			/*! Adds a vector to the current vector
			\param RHS The vector to add to the current vector
			\returns The two vectors added together
			*/
			Vector3& operator+=( const Vector3 &RHS )
			{
				X_ += RHS.X_;
				Y_ += RHS.Y_;
				Z_ += RHS.Z_;
				return *this;
			}

			/*! Subtracts a vector from the current vector
			\param RHS The vector to be subtracted from the current vector
			\returns The current vector with RHS subtracted from it
			*/
			Vector3& operator-=( const Vector3 &RHS )
			{
				X_ -= RHS.X_;
				Y_ -= RHS.Y_;
				Z_ -= RHS.Z_;
				return *this;
			}

			/*! The current vector multiplied by a scalar
			\param RHS The scalar the vector should be multiplied by
			\returns The vector multiplied by the scalr
			*/
			Vector3& operator*=( const T_ &RHS )
			{
				X_ *= RHS;
				Y_ *= RHS;
				Z_ *= RHS;
				return *this;

			}

			/*! The current vector divided by a scalar
			\param RHS The scalar the vector should be divided by
			\returns The vector divided by the scalr
			*/
			Vector3& operator/=( const T_ &RHS )
			{
				X_ /= RHS;
				Y_ /= RHS;
				Z_ /= RHS;
				return *this;
			}

			/*! Creates a new vector from the current vector's X and Y coordinates
			\returns A vector 2 built from the X and Y components of this vector
			*/
			Vector2<T_> XY()
			{
				return Vector2<T_>( X_, Y_ );
			}

			/*! Creates a new vector from the current vector's X and Z coordinates
			\returns A vector 2 built from the X and Z components of this vector
			*/
			Vector2<T_> XZ()
			{
				return Vector2<T_>( X_, Z_ );
			}

			/*! Creates a new vector from the current vector's Y and Z coordinates, in that order
			\returns A vector 2 built from the Y and Z components of this vector
			*/
			Vector2<T_> YZ()
			{
				return Vector2<T_>( Y_, Z_ );
			}
		};

		/*! Multiplies a scalar by a vector
		\param LHS The scalar that is being multiplied
		\param V The vector that the scalar is being multiplied by
		\returns A vector multiplied by the scalar
		*/
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
