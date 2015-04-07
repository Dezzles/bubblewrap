#ifndef STATICLOG_HPP
#define STATICLOG_HPP

#include <string>

namespace Bubblewrap
{
	namespace Logs
	{
		class Log;
		class StaticLog
		{
			friend Log;
		public:
			enum Level
			{
				CRITICAL = 0,
				ERROR,
				WARNING,
				INFO,
				VERBOSE
			};
			void Write( std::string Log, Level LogLevel );
			void WriteLine( std::string Log, Level LogLevel );

			void WriteNoIndent( std::string Log, Level LogLevel );
			void WriteLineNoIndent( std::string Log, Level LogLevel );

			static StaticLog* Instance()
			{
				if ( Instance_ == nullptr )
					Instance_ = new StaticLog();
				return Instance_;
			}
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