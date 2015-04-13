#ifndef BUBBLEWRAP_BASE_DTYPE_HPP
#define BUBBLEWRAP_BASE_DTYPE_HPP

#include <stdlib.h>
#include <assert.h>

namespace Bubblewrap
{
	namespace Base
	{
		/*! A boolean object that has a default value of false
		*/
		class DBool
		{
		public:
			/*! Initialises the object to false
			*/
			DBool() : Value_( false )
			{

			}
			/*! Assigns a value to the object
			\param V The value to be assigned
			*/
			void operator=( bool V )
			{
				Value_ = V;
			}

			/*! Compares the object to a value
				\param V The value to be compared to
				\return True if the current value matches V
			*/
			bool operator==( bool V )
			{
				return V == Value_;
			}
			/*! Gets the value currently stored by the object
			*/
			operator bool() const
			{
				return( Value_ );
			}
		private:
			bool Value_;
		};

		/*! A dynamic type where you can assign the default value of the object
		*/
		template <typename T, T Val>
		class DType
		{
		public:
			/*! Initialises the object to its default value
			*/
			DType() : Value_( Val )
			{

			}
			/*! Assigns a value to the object
				\param V The value to be assigned to the object
			*/
			void operator=( T V )
			{
				Value_ = V;
			}
			/*! Compares the object to a value
				\param V The value to be compared to
				\return True if the current value matches V
			*/
			bool operator==( T V )
			{
				return V == Value_;
			}
			/*! Returns the value currently stored in the object
			*/
			operator T() const
			{
				return( Value_ );
			}
			/*! Gets a pointer to the internal value
			*/
			T operator->( ) const
			{
				return Value_;
			}
			/*! Directly returns the default value
			*/
			T Value()
			{
				return Value_;
			}
		private:
			T Value_;
		};

		/*! A stupid boolean wrapper that probably should never be used
		*/
		class QBool
		{
		public:
			/*! Initialises the stupid boolean
			*/
			QBool()
			{
			}
			/*! Assigns a value to the stupid boolean object
				\param V The value to be assigned
			*/
			void operator=( bool V )
			{
				Value_ = V ? 1 : 0;
			}
			/*! Compares the object to a value. This forces a random value into the bool
				\param V The value to be compared to
				\return If V is equal to the internal value
			*/
			bool operator==( bool V )
			{
				if ( Value_ == -1 )
				{
					Value_ = rand() % 2;
				}
				return V == (Value_ == 1);
			}
			/*! Gets the value of the object. This forces a random value into the bool
			*/
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