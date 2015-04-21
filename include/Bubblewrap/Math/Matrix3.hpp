#ifndef BUBBLEWRAP_MATH_MATRIX3_HPP
#define BUBBLEWRAP_MATH_MATRIX3_HPP

#include "Bubblewrap/Math/Vector2.hpp"

namespace Bubblewrap
{
	namespace Math
	{
		/*! Holds a 3x3 matrix
		*/
		template < typename T_ >
		class Matrix3
		{
		public:
			/*! Creates an identity matrix
			*/
			Matrix3()
			{
				for ( int Idx = 0; Idx < 9; ++Idx )
					Matrix_[ Idx ] = ( T_ )( ( ( Idx % 3 ) == ( Idx / 3 ) ) ? 1 : 0 );
			}
			/*! Creates a new matrix
			\param i00 Initialises a component of the matrix
			\param i01 Initialises a component of the matrix
			\param i02 Initialises a component of the matrix
			\param i10 Initialises a component of the matrix
			\param i11 Initialises a component of the matrix
			\param i12 Initialises a component of the matrix
			\param i20 Initialises a component of the matrix
			\param i21 Initialises a component of the matrix
			\param i22 Initialises a component of the matrix
			*/
			Matrix3( T_ i00, T_ i01, T_ i02, T_ i10, T_ i11, T_ i12, T_ i20, T_ i21, T_ i22 )
			{
				Matrix_[ 0 ] = i00;
				Matrix_[ 1 ] = i01;
				Matrix_[ 2 ] = i02;
				Matrix_[ 3 ] = i10;
				Matrix_[ 4 ] = i11;
				Matrix_[ 5 ] = i12;
				Matrix_[ 6 ] = i20;
				Matrix_[ 7 ] = i21;
				Matrix_[ 8 ] = i22;
			}

			/*! Adds two matrices objects together
			\param Oth The matrix to be added
			\returns A matrix representing the addition of two matrices
			*/
			Matrix3 operator+( const Matrix3 &Oth )
			{
				Matrix3 ret;
				for ( int Idx = 0; Idx < 9; ++Idx )
				{
					ret.Matrix_[ Idx ] = Matrix_[ 0 ] + Oth.Matrix_[ 0 ];
				}
				return ret;
			}

			/*! Subtracts a matrix from this matrix
			\param Oth The matrix to subtract
			\returns The matrix produced by subtracting another matrix from this one
			*/
			Matrix3 operator-( const Matrix3 &Oth )
			{
				Matrix3 ret;
				for ( int Idx = 0; Idx < 9; ++Idx )
				{
					ret.Matrix_[ Idx ] = Matrix_[ 0 ] - Oth.Matrix_[ 0 ];
				}
				return ret;
			}


			/*! Multiplies a matrix by a scalar value
			\param M A scalar value the matrix should be multiplied by
			\returns A New matrix where the components are multipied by M
			*/
			Matrix3 operator*( const T_ M ) const
			{
				Matrix3 ret;
				for ( int Idx = 0; Idx < 9; ++Idx )
				{
					ret.Matrix_[ Idx ] = Matrix_[ 0 ] * M;
				}
				return ret;
			}

			/*! Divides the matrix by a scalar value
			\param M The scalar value the matrix will be divided by
			\returns A new matrix where the components are divided by M
			*/
			Matrix3 operator/( const T_ M ) const
			{
				Matrix3 ret;
				for ( int Idx = 0; Idx < 9; ++Idx )
				{
					ret.Matrix_[ Idx ] = Matrix_[ 0 ] / M;
				}
				return ret;
			}

			/*! Multiplies a vector by a matrix
			\param V The vector to multiply by
			\returns The resulting vector from the multiplication
			*/
			Vector2<T_> operator*( const Vector2<T_> V ) const
			{
				auto ret = Vector2<T_>(
					V.X_ * Matrix_[ 0 ] + V.Y_ * Matrix_[ 1 ] + Matrix_[ 2 ],
					V.X_ * Matrix_[ 3 ] + V.Y_ * Matrix_[ 4 ] + Matrix_[ 5 ]
					);
				return ret;
			}

			/*! Multiplies a vector by a matrix
			\param V The vector to multiply by
			\returns The resulting vector from the multiplication
			*/
			Vector3<T_> operator*( const Vector3<T_> V ) const
			{
				return Vector3<T_>(
					V.X_ * Matrix_[ 0 ] + V.Y_ * Matrix_[ 1 ] + Matrix_[ 2 ],
					V.X_ * Matrix_[ 3 ] + V.Y_ * Matrix_[ 4 ] + Matrix_[ 5 ],
					V.X_ * Matrix_[ 6 ] + V.Y_ * Matrix_[ 7 ] + Matrix_[ 8 ]
					);
			}

			/*! Gets the 0,0th item in the Matrix
			\returns A float representing a value in the matrix
			*/
			T_ I00() const { return Matrix_[ 0 * Rows + 0 ]; }

			/*! Gets the 0,1th item in the Matrix
			\returns A float representing a value in the matrix
			*/
			T_ I01() const { return Matrix_[ 0 * Rows + 1 ]; }

			/*! Gets the 0,2th item in the Matrix
			\returns A float representing a value in the matrix
			*/
			T_ I02() const{ return Matrix_[ 0 * Rows + 2 ]; }

			/*! Gets the 1,0th item in the Matrix
			\returns A float representing a value in the matrix
			*/
			T_ I10() const { return Matrix_[ 1 * Rows + 0 ]; }

			/*! Gets the 1,1th item in the Matrix
			\returns A float representing a value in the matrix
			*/
			T_ I11() const { return Matrix_[ 1 * Rows + 1 ]; }

			/*! Gets the 1,2th item in the Matrix
			\returns A float representing a value in the matrix
			*/
			T_ I12() const { return Matrix_[ 1 * Rows + 2 ]; }

			/*! Gets the 2,0th item in the Matrix
			\returns A float representing a value in the matrix
			*/
			T_ I20() const
			{
				return Matrix_[ 2 * Rows + 0 ];
			}

			/*! Gets the 2,1th item in the Matrix
			\returns A float representing a value in the matrix
			*/
			T_ I21() const
			{
				return Matrix_[ 2 * Rows + 1 ];
			}

			/*! Gets the 2,2th item in the Matrix
			\returns A float representing a value in the matrix
			*/
			T_ I22() const
			{
				return Matrix_[ 2 * Rows + 2 ];
			}

			/*! Creates a rotation matrix
			\param Theta The amount, in radians, that the matrix will rotate a 2D vector 
			\returns A rotation matrix
			*/
			static Matrix3 RotationMatrix( T_ Theta )
			{
				return Matrix3(
					( T_ ) cos( Theta ), -( T_ ) sin( Theta ), 0,
					( T_ ) sin( Theta ), ( T_ ) cos( Theta ), 0,
					0, 0, 1 );
			}

			/*! Creates a scaling matrix for Vector2
			\param Sx The amount by which the X value should be scaled
			\param Sy The amount by which the Y value should be scaled
			\returns A scaling matrix
			*/
			static Matrix3 ScalingMatrix( T_ Sx, T_ Sy )
			{
				return Matrix3(
					Sx, 0, 0,
					0, Sy, 0,
					0, 0, 1 );
			}
			/*! Creates a scaling matrix for Vector3
			\param Sx The amount by which the X value should be scaled
			\param Sy The amount by which the Y value should be scaled
			\param Sz The amount by which the Z value should be scaled
			\returns A scaling matrix
			*/
			static Matrix3 ScalingMatrix( T_ Sx, T_ Sy, T_ Sz )
			{
				return Matrix3(
					Sx, 0, 0,
					0, Sy, 0,
					0, 0, Sz );
			}

			/*! Creates a translation matrix for Vector2
			\param Tx The amount by which the X value should be translated
			\param Ty The amount by which the Y value should be translated
			\returns A scaling matrix
			*/
			static Matrix3 Translationmatrix( T_ Tx, T_ Ty )
			{
				return Matrix3(
					1, 0, Tx,
					0, 1, Ty,
					0, 0, 1 );
			}

		private:

			T_ Matrix_[ 3 * 3 ];
			static const int Rows = 3;
			static const int Cols = 3;
		};

		/*! Multiplies a scalar by a matrix
		\param LHS The scalar that is being multiplied
		\param M The matrix that the scalar is being multiplied by
		\returns A matrix multiplied by the scalar
		*/
		template< typename T_ >
		Matrix3<T_> operator*( const T_ LHS, const Matrix3<T_> M )
		{
			return M * LHS;
		}

		typedef Matrix3<float> Matrix3f;
		typedef Matrix3<double> Matrix3d;
		typedef Matrix3<int> Matrix3i;
	}
}



#endif