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
			
			void Write( std::string Log );
			void WriteLine( std::string Log );

			static StaticLog* Instance()
			{
				if ( Instance_ == nullptr )
					Instance_ = new StaticLog();
				return Instance_;
			}
		private:
			void Indent();
			void Undent();

			static StaticLog* Instance_;
			int Indent_ = -1;
		};

	}
}


#endif