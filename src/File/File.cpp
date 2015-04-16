#include "Bubblewrap/File/File.hpp"
#include "Bubblewrap/Base/Assert.hpp"
#include "physfs.h"

Bubblewrap::File::File::File()
{

}

void Bubblewrap::File::File::Open( FileMode Mode )
{
	PhysFSFile_ = PHYSFS_openRead( Path_.c_str() );
}

void Bubblewrap::File::File::Close()
{ 
	PHYSFS_close( ( PHYSFS_File* )PhysFSFile_ );
}


int Bubblewrap::File::File::Get()
{ 
	AssertMessage( false, "Not implemented" );
	return 0;
}

void Bubblewrap::File::File::Get( char& C )
{
	AssertMessage( false, "Not implemented" );
	C = 0;

}

void Bubblewrap::File::File::Get( char* S, unsigned int Size )
{
	AssertMessage( false, "Not implemented" );
	S = nullptr;
}

void Bubblewrap::File::File::Get( char* S, unsigned int Size, char Delim )
{
	AssertMessage( false, "Not implemented" );
	S = nullptr;
}

void Bubblewrap::File::File::GetLine( char* S, unsigned int Size )
{
	AssertMessage( false, "Not implemented" );
	S = nullptr;
}

void Bubblewrap::File::File::GetLine( char* S, unsigned int Size, char Delim )
{
	AssertMessage( false, "Not implemented" );
	S = nullptr;
}

int Bubblewrap::File::File::Peek()
{
	AssertMessage( false, "Not implemented" );
	return 0;


}

void Bubblewrap::File::File::Read( char* S, unsigned int Size )
{
	AssertMessage( false, "Not implemented" );
	S = nullptr;

}

unsigned int Bubblewrap::File::File::TellRead()
{
	AssertMessage( false, "Not implemented" );
	return 0;

}

unsigned int Bubblewrap::File::File::TellWrite()
{
	AssertMessage( false, "Not implemented" );
	return 0;

}

void Bubblewrap::File::File::SeekRead( unsigned int Pos )
{
	AssertMessage( false, "Not implemented" );
}

void Bubblewrap::File::File::SeekRead( unsigned int Pos, SeekDir Dir )
{
	AssertMessage( false, "Not implemented" );
}

void Bubblewrap::File::File::SeekWrite( unsigned int Pos )
{
	AssertMessage( false, "Not implemented" );
}

void Bubblewrap::File::File::SeekWrite( unsigned int Pos, SeekDir Dir )
{
	AssertMessage( false, "Not implemented" );
}

void Bubblewrap::File::File::Put( char C )
{
	AssertMessage( false, "Not implemented" );
}

void Bubblewrap::File::File::Write( const char* S, unsigned int Size )
{
	AssertMessage( false, "Not implemented" );
}

bool Bubblewrap::File::File::IsOpen()
{
	return ( PhysFSFile_ != nullptr );
}

int Bubblewrap::File::File::Size()
{
	if ( PhysFSFile_ == nullptr )
		return -1;
	return PHYSFS_fileLength( ( PHYSFS_File* ) PhysFSFile_ );
}

char* Bubblewrap::File::File::ReadAll()
{
	if ( PhysFSFile_ == nullptr )
		return nullptr;
	char *myBuf;
	myBuf = new char[ PHYSFS_fileLength( ( PHYSFS_File* ) PhysFSFile_ ) ];
	int length_read = PHYSFS_read( ( PHYSFS_File* ) PhysFSFile_, myBuf, 1, PHYSFS_fileLength( ( PHYSFS_File* ) PhysFSFile_ ) );
	return myBuf;
}