#ifndef LOGS_HPP
#define LOGS_HPP


#include <string>

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
			void Write( std::string Log );
			void WriteLine( std::string Log );
		private:
			std::string Grouping_;
			bool GroupingSet_;
		};
	}
}



#endif