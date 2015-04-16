#ifndef BUBBLEWRAP_FILE_FILESYSTEM_HPP
#define BUBBLEWRAP_FILE_FILESYSTEM_HPP

#include <fstream>
#include <streambuf>
#include "Bubblewrap/File/File.hpp"
namespace Bubblewrap
{
	namespace File
	{
		/*! Wraps PhysFS*/
		class FileSystem
		{
		public :
			void Initialise();
			void AddPath( std::string Path, bool AddToFront );
			bool FileExists( std::string Path );
			File GetFile( std::string Path );
		};

	}
}




#endif