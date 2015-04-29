#include "Bubblewrap/File/FileSystem.hpp"
#include "Bubblewrap/File/File.hpp"
#include <physfs/physfs.h>

void Bubblewrap::File::FileSystem::Initialise()
{
	PHYSFS_init( NULL );
}

void Bubblewrap::File::FileSystem::AddPath( std::string Path, bool AddToFront )
{
	PHYSFS_mount( Path.c_str(), NULL, AddToFront ? 0 : 1 );
}

bool Bubblewrap::File::FileSystem::FileExists( std::string Path )
{
	return ( PHYSFS_exists( Path.c_str() ) > 0 );
}

Bubblewrap::File::File Bubblewrap::File::FileSystem::GetFile( std::string Path )
{
	Bubblewrap::File::File ret;
	ret.Path_ = Path;
	return ret;
}