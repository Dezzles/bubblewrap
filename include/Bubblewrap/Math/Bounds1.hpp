#ifndef BUBBLEWRAP_BOUNDS1_HPP
#define BUBBLEWRAP_BOUNDS1_HPP

namespace Bubblewrap
{
	namespace Math
	{
		/*! Object designed for the defining of one dimensional ranges */
		template < typename T_ >
		class Bounds1
		{
		private:
			T_ Upper_;
			T_ Lower_;

		public:
			/*! Initialises the bounds to 0.0 - 0.0 */
			Bounds1()
				: Lower_( 0.0f ), Upper_( 0.0f )
			{
			}

			/*! Sets the current bounds for the object. The object will automatically set the
				lower value passed in as the Lower bound and the higher as the Upper bound.
				\param Lower The lower bound value
				\param Upper The higher bound value
			*/
			void SetBounds( T_ Lower, T_ Upper )
			{
				Upper_ = Upper;
				Lower_ = Lower;
				if ( Upper < Lower )
				{
					Upper_ = Lower;
					Lower_ = Upper;
				}

			}

			/*! Initialises the object with bounds set. The object will automatically set the
			lower value passed in as the Lower bound and the higher as the Upper bound.
			\param Lower The lower bound value
			\param Upper The higher bound value
			*/
			Bounds1( T_ Lower, T_ Upper )
				: Lower_( Lower ), Upper_( Upper )
			{
				if ( Upper < Lower )
				{
					Upper_ = Lower;
					Lower_ = Upper;
				}
			}

			/*! Gets the range of the bounds.
			\returns The difference between the Upper and Lower bounds.
			*/
			T_ Range()
			{
				return Upper_ - Lower;
			}

			/*! Gets the lower bounds
			\returns The lower bounds used
			*/
			T_ Lower()
			{
				return Lower_;
			}

			/*! Gets the upper bounds
			\returns The upper bounds used
			*/
			T_ Upper()
			{
				return Upper_;
			}

			/*! Restricts a value to be inside the current bounds
			\param Val The value that needs to be restricted
			\returns The value, if it is inside the bounds. Otherwise the Upper or Lower bound depending on Val.
			*/
			T_ Restrict( T_ Val )
			{
				return ( Val < Lower_ ? Lower_ : ( Val > Upper_ ? Upper_ : Val ) );
			}

			/*! Checks whether a value is inside the bounds or not 
			\param Val The value being tested
			\returns True if the value is greater than or equal to Lower and less than or equal to Upper
			*/
			bool Inside( T_ Val )
			{
				return ( ( Lower_ < Val ) && ( Val < Upper_ ) );
			}


			/*! Checks whether a value is inside the bounds or not
			\param f First The value being tested
			\returns True if the value is greater than or equal to Lower and less than or equal to Upper
			*/
			template< typename First>
			bool IsInside( First f )
			{
				return Inside( f );
			}

			/*! Checks whether a group of values is inside the bounds or not
			\param f The first value being tested
			\param rest The rest of the values being tested
			\returns True if the value is greater than or equal to Lower and less than or equal to Upper
			*/
			template< typename First, typename ...Rest>
			bool IsInside( First f, Rest ...rest )
			{
				return Inside( f ) && ( Inside( rest... ) );
			}

			/*! Shrinks the size of the bounds. Bounds will be shrunk evenly from both ends. If Val is greater than the 
				range of the bounds, both Upper and Lower will meet at the midpoint.
			\param Val The amount that the bounds should be shrunk.
			*/
			void ShrinkBounds( T_ Val )
			{
				T_ half = Val * 0.5f;
				if ( Lower_ + half > Upper_ - half )
				{
					float mid = ( Upper_ + Lower_ ) * 0.5f;
					Lower_ = mid;
					Upper_ = mid;
				}
				else
				{
					Lower_ += Val / 2.0f;
					Upper_ -= Val / 2.0f;
				}
			}

			/*! Shrinks the size of the bounds. Lower value will be increased. If Val is greater than the
			range of the bounds, Lower will equal Upper.
			\param Val The amount that the bounds should be shrunk.
			*/
			void ShrinkLower( T_ Val )
			{
				Lower_ += Val;
				if ( Lower_ > Upper_ )
					Lower_ = Upper_;
			}

			/*! Shrinks the size of the bounds. Upper value will be increased. If Val is greater than the
			range of the bounds, Upper will equal Lower.
			\param Val The amount that the bounds should be shrunk.
			*/
			void ShrinkUpper( T_ Val )
			{
				Upper_ -= Val;
				if ( Upper_ < Lower_ )
					Upper_ = Lower_;
			}

			/*! Increases the size of the bounds. Bounds will grow evenly
			\param Val The amount that the bounds should be grown.
			*/
			void GrowBounds( T_ Val )
			{
				ShrinkBounds( -Val );
			}

			/*! Increases the size of the bounds. Bounds will be grow from Lower. 
			\param Val The amount that the bounds should be grown.
			*/
			void GrowLower( T_ Val )
			{
				ShrinkLower( -Val );
			}

			/*! Increases the size of the bounds. Bounds will be grow from Upper.
			\param Val The amount that the bounds should be grown.
			*/
			void GrowUpper( T_ Val )
			{
				ShrinkUpper( -Val );
			}
		};

		typedef Bounds1<float> Bounds1f;
		typedef Bounds1<int> Bounds1i;
		typedef Bounds1<double> Bounds1d;
	}
}



#endif