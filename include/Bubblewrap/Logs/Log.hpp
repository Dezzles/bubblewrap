#ifndef LOGS_HPP
#define LOGS_HPP


#include <string>
#include "Bubblewrap/Logs/StaticLog.hpp"
namespace Bubblewrap
{
	namespace Logs
	{
		class Log
		{
		public:
			Log( std::string Grouping );
			Log( );
			~Log();
			void Write( std::string Log, StaticLog::Level LogLevel );
			void WriteLine( std::string Log, StaticLog::Level LogLevel );
		private:
			std::string Grouping_;
			bool GroupingSet_;
		};
	}
}



#endif