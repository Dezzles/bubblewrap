#ifndef LOGS_HPP
#define LOGS_HPP


#include <string>
#include "Bubblewrap/Logs/StaticLog.hpp"
namespace Bubblewrap
{
	namespace Logs
	{
		/*! Class for creating Logs, especially useful for logging specific functions*/
		class Log
		{
		public:
			/*! Creates the log with a specific grouping. This will automatically log when the 
				Log is created and descoped using Grouping name. It will also indent all items
				logged against it
				\param Grouping The name that should be displayed for "Entering" and "Exiting" in the log
			*/
			Log( std::string Grouping );
			/*! Creates a new instance of Log */
			Log( );
			/*! Destroys the Log. If the Log was created with a grouping then it will automatically log
				that it has been exited.
			*/
			~Log();
			/*! Writes a string to the log. 
				\param Log The information to log
				\param LogLevel The level by which the log will be written. If this is below the current log
					level then it will not be shown.
			*/
			void Write( std::string Log, StaticLog::Level LogLevel );
			/*! Writes a string to the log with a new line.
			\param Log The information to log
			\param LogLevel The level by which the log will be written. If this is below the current log
			level then it will not be shown.
			*/
			void WriteLine( std::string Log, StaticLog::Level LogLevel );
		private:
			std::string Grouping_;
			bool GroupingSet_;
		};
	}
}



#endif