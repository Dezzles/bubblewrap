#ifndef BUBBLEWRAP_BOUNDS1_HPP
#define BUBBLEWRAP_BOUNDS1_HPP

namespace Bubblewrap
{
	namespace Math
	{
		template < typename T_ >
		class Bounds1
		{
		private:
			T_ Upper_;
			T_ Lower_;

		public:
			Bounds1()
				: Lower_( 0.0f ), Upper_( 0.0f )
			{
			}

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

			Bounds1( T_ Lower, T_ Upper )
				: Lower_( Lower ), Upper_( Upper )
			{
				if ( Upper < Lower )
				{
					Upper_ = Lower;
					Lower_ = Upper;
				}
			}

			T_ Range()
			{
				return Upper_ - Lower;
			}

			T_ Lower()
			{
				return Lower_;
			}

			T_ Upper()
			{
				return Upper_;
			}

			T_ Restrict( T_ Val )
			{
				return ( Val < Lower_ ? Lower_ : ( Val > Upper_ ? Upper_ : Val ) );
			}

			bool Inside( T_ Val )
			{
				return ( ( Lower_ < Val ) && ( Val < Upper_ ) );
			}

			template< typename First>
			bool IsInside( First f )
			{
				return Inside( f );
			}



			template< typename First, typename ...Rest>
			bool IsInside( First f, Rest ...rest )
			{
				return Inside( f ) && ( Inside( rest... ) );
			}

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

			void ShrinkLower( T_ Val )
			{
				Lower_ += Val;
				if ( Lower_ > Upper_ )
					Lower_ = Upper_;
			}

			void ShrinkUpper( T_ Val )
			{
				Upper_ -= Val;
				if ( Upper_ < Lower_ )
					Upper_ = Lower_;
			}

			void GrowBounds( T_ Val )
			{
				ShrinkBounds( -Val );
			}

			void GrowLower( T_ Val )
			{
				ShrinkLower( -Val );
			}

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