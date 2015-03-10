#ifndef DTYPE_H
#define DTYPE_H

#include <stdlib.h>
#include <assert.h>



namespace Bubblewrap
{
	namespace Base
	{
		class DBool
		{
		public:
			DBool() : Value_( false )
			{

			}
			void operator=( bool V )
			{
				Value_ = V;
			}
			bool operator==( bool V )
			{
				return V == Value_;
			}
			operator bool() const
			{
				return( Value_ );
			}
		private:
			bool Value_;
		};

		template <typename T, T Val>
		class DType
		{
		public:
			DType() : Value_( Val )
			{

			}
			void operator=( T V )
			{
				Value_ = V;
			}
			bool operator==( T V )
			{
				return V == Value_;
			}
			operator T() const
			{
				return( Value_ );
			}
			T operator->( ) const
			{
				return Value_;
			}
		private:
			T Value_;
		};

		class QBool
		{
		public:
			QBool()
			{
			}
			void operator=( bool V )
			{
				Value_ = V ? 1 : 0;
			}
			bool operator==( bool V )
			{
				if ( Value_ == -1 )
				{
					Value_ = Value_ % 2;
				}
				return V == (Value_ == 1);
			}
			operator bool()
			{
				if ( Value_ == -1 )
				{
					Value_ = Value_ % 2;
				}
				return( Value_ == 1 );
			}
		private:
			int Value_;
		};

	}
}

#endif