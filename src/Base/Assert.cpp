#include "Bubblewrap/Base/Assert.hpp"
#include "Bubblewrap/Logs/StaticLog.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		void Assert::DoAssert( std::string Message )
		{
			Logs::StaticLog::Instance()->WriteLineNoIndent( std::string( "ASSERT: " ) + Message, Logs::StaticLog::CRITICAL );
			Logs::StaticLog::Instance()->WriteNoIndent("Break? ( y/n ) > ", Logs::StaticLog::CRITICAL );
			char c = getchar();

			if ( ( c == 'y' ) || ( c == 'Y' ) )
			{
				throw Message;
			}
		}

		void Assert::ThrowWarning( std::string Message )
		{
			Logs::StaticLog::Instance()->WriteLineNoIndent( std::string( "Warning: " ) + Message, Logs::StaticLog::WARNING );
		}

	}
}