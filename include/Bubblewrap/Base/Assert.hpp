#ifndef BUBBLEWRAP_BASE_ASSERT_HPP
#define BUBBLEWRAP_BASE_ASSERT_HPP
#include <string>
namespace Bubblewrap
{
	namespace Base
	{
		//!  Assert wraps all functions used to throw warnings and asserts
		class Assert
		{
		public:
			//! Throws an assert message
			/*!
				\param Message The message that will be shown to the user
			*/
			static void DoAssert( std::string Message );

			//! Displays a warning message to the user
			/*!
				\param Message the warning message that will be shown to the user
			*/
			static void ThrowWarning( std::string Message );
		};

#define AssertExpr( Expr_ ) if ( !(Expr_ ) ) Bubblewrap::Base::Assert::DoAssert( #Expr_ );
#define AssertMessage( Expr_ , Message_ ) if ( !(Expr_ ) ) Bubblewrap::Base::Assert::DoAssert( Message_ );
#ifdef CRASHNBURN
#define HardTest( Expr_, Message_ ) AssertMessage( (Expr_ ), Message_ );
#else
#define HardTest( Expr_, Message_ ) Bubblewrap::Base::Assert::ThrowWarning( Message_ );
#endif 
	}
}




#endif