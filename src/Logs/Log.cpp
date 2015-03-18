#include "Bubblewrap/Logs/Log.hpp"
#include "Bubblewrap/Logs/StaticLog.hpp"



namespace Bubblewrap
{
	namespace Logs
	{

		Log::Log( std::string Grouping )
		{
			WriteLine( "Entering: " + Grouping );
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
				WriteLine( "Exiting: " + Grouping_ );
		}

		void Log::Write( std::string Log )
		{
			StaticLog::Instance()->Write( Log );
		}

		void Log::WriteLine( std::string Log )
		{
			StaticLog::Instance()->WriteLine( Log );
		}

	}
}
