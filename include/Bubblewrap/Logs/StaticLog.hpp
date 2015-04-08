#ifndef STATICLOG_HPP
#define STATICLOG_HPP

#include <string>

namespace Bubblewrap
{
	namespace Logs
	{
		class Log;
		/*! A static log designed to handle all logging tasks. Generally logging should be performed through the
			Log class.*/
		class StaticLog
		{
			friend Log;
		public:
			/*! Indicates different degrees of logs */
			enum Level
			{
				/*! Highest priority, will always be displayed */
				CRITICAL = 0,
				/*! Errors that occur during run time */
				ERROR,
				/*! Displays warnings about code that may cause defects */
				WARNING,
				/*! Pure information */
				INFO,
				/*! More information than you probably want */
				VERBOSE
			};
			/*! Writes a string to the log, this will automatically indent.
			\param Log The information to log
			\param LogLevel The level by which the log will be written. If this is below the current log
			level then it will not be shown.
			*/
			void Write( std::string Log, Level LogLevel );
			/*! Writes a string to the log with a new line, this will automatically indent.
			\param Log The information to log
			\param LogLevel The level by which the log will be written. If this is below the current log
			level then it will not be shown.
			*/
			void WriteLine( std::string Log, Level LogLevel );

			/*! Writes a string to the log with no indenting.
			\param Log The information to log
			\param LogLevel The level by which the log will be written. If this is below the current log
			level then it will not be shown.
			*/
			void WriteNoIndent( std::string Log, Level LogLevel );

			/*! Writes a string to the log with no indenting and a new line.
			\param Log The information to log
			\param LogLevel The level by which the log will be written. If this is below the current log
			level then it will not be shown.
			*/
			void WriteLineNoIndent( std::string Log, Level LogLevel );

			/*! Returns and instnace of the StaticLog and, if one doesn't exist, creates one first. 
			\returns An instance of the StaticLog singleton.
			*/
			static StaticLog* Instance()
			{
				if ( Instance_ == nullptr )
					Instance_ = new StaticLog();
				return Instance_;
			}
			/*! Sets the current level of logging that we care about. 
			\param NewLevel The logging highest logging level that should be output */
			void SetLogLevel( Level NewLevel );
		private:
			void Indent();
			void Undent();

			Level LogLevel_;
			static StaticLog* Instance_;
			int Indent_ = -1;

			StaticLog();
		};

	}
}


#endif