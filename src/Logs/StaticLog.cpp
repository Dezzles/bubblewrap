#include "Bubblewrap/Logs/StaticLog.hpp"



namespace Bubblewrap
{
	namespace Logs
	{
		StaticLog* StaticLog::Instance_ = 0;

		void StaticLog::Write( std::string Log )
		{
			int space = 1 + Indent_ * 2;
			printf( "%*s%s", space, "-", Log.c_str() );
		}

		void StaticLog::WriteLine( std::string Log )
		{
			int space = 1 + Indent_ * 2;
			printf( "%*s%s", space, "-", Log.c_str() );
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
	}
}
