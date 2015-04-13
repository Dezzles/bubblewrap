#include "Bubblewrap/Logs/StaticLog.hpp"



namespace Bubblewrap
{
	namespace Logs
	{
		StaticLog* StaticLog::Instance_ = 0;

		StaticLog::StaticLog()
		{
			LogLevel_ = WARNING;
		}

		void StaticLog::Write( std::string Log, Level LogLevel )
		{
			if ( LogLevel > LogLevel_ )
				return;
			int space = 1 + Indent_ * 2;
			printf( "%*s%s", space, "-", Log.c_str() );
		}

		void StaticLog::WriteLine( std::string Log, Level LogLevel )
		{
			if ( LogLevel > LogLevel_ )
				return;
			int space = 1 + Indent_ * 2;
			printf( "%*s%s", space, "-", Log.c_str() );
			printf( "\n" );
		}

		void StaticLog::WriteNoIndent( std::string Log, Level LogLevel )
		{
			if ( LogLevel > LogLevel_ )
				return;
			printf( "%s", Log.c_str() );
			printf( "\n" );
		}

		void StaticLog::WriteLineNoIndent( std::string Log, Level LogLevel )
		{
			if ( LogLevel > LogLevel_ )
				return;
			printf( "%s", Log.c_str() );
			printf( "\n" );
		}

		void StaticLog::Indent()
		{
			++Indent_;
		}

		void StaticLog::Undent()
		{
			--Indent_;
		}

		void StaticLog::SetLogLevel( Level NewLevel )
		{
			LogLevel_ = NewLevel;
		}
	}
}
