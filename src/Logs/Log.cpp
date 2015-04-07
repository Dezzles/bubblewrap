#include "Bubblewrap/Logs/Log.hpp"
#include "Bubblewrap/Logs/StaticLog.hpp"



namespace Bubblewrap
{
	namespace Logs
	{

		Log::Log( std::string Grouping )
		{
			WriteLine( "Entering: " + Grouping, StaticLog::INFO );
			StaticLog::Instance()->Indent();
			GroupingSet_ = true;
			Grouping_ = Grouping;
		}

		Log::Log( )
		{
			StaticLog::Instance()->Indent();
			GroupingSet_ = false;
		}

		Log::~Log()
		{
			StaticLog::Instance()->Undent();
			if ( GroupingSet_ )
				WriteLine( "Exiting: " + Grouping_, StaticLog::INFO );
		}

		void Log::Write( std::string Log, StaticLog::Level LogLevel )
		{
			StaticLog::Instance()->Write( Log, LogLevel );
		}

		void Log::WriteLine( std::string Log, StaticLog::Level LogLevel )
		{
			StaticLog::Instance()->WriteLine( Log, LogLevel );
		}

	}
}
