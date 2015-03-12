#include "Bubblewrap/File/FSFile.hpp"

namespace Bubblewrap
{
	namespace File
	{
		FiFSFile::FiFSFile( std::string Filename )
			: Filename_( Filename )
		{
		}
		FiFSFile::~FiFSFile()
		{
		}

		void FiFSFile::Open( FsMode Mode )
		{
			std::ios_base::open_mode mode = 0;

			if ( Is( Mode, FsMode::Read ) )
				mode = mode | std::ios::in;
			if ( Is( Mode, FsMode::Write ) )
				mode = mode | std::ios::out;
			if ( Is( Mode, FsMode::Binary ) )
				mode = mode | std::ios::binary;

			Stream_.open( Filename_.c_str(), mode );
		}

		void FiFSFile::Close()
		{
			Stream_.close();
		}

		int FiFSFile::Get()
		{
			return Stream_.get();
		}
		void FiFSFile::Get( char& C )
		{
			Stream_.get( C );
		}
		void FiFSFile::Get( char* S, unsigned int Size )
		{
			Stream_.get( S, Size );
		}
		void FiFSFile::Get( char* S, unsigned int Size, char Delim )
		{
			Stream_.get( S, Size, Delim );
		}

		void FiFSFile::GetLine( char* S, unsigned int Size )
		{
			Stream_.getline( S, Size );
		}
		void FiFSFile::GetLine( char* S, unsigned int Size, char Delim )
		{
			Stream_.getline( S, Size, Delim );
		}

		int FiFSFile::Peek()
		{
			return Stream_.peek();
		}

		void FiFSFile::Read( char* S, unsigned int Size )
		{
			Stream_.read( S, Size );
		}

		unsigned int FiFSFile::TellRead()
		{
			return static_cast< unsigned int >( Stream_.tellg() );
		}

		unsigned int FiFSFile::TellWrite()
		{
			return static_cast< unsigned int >( Stream_.tellp() );
		}

		void FiFSFile::SeekRead( unsigned int Pos )
		{
			Stream_.seekg( Pos );
		}

		void FiFSFile::SeekRead( unsigned int Pos, FsSeekDir Dir )
		{
			std::ios::seekdir dir = std::ios::beg;
			if ( Dir == FsSeekDir::End )
				dir = std::ios::end;
			Stream_.seekg( Pos, dir );
		}

		void FiFSFile::SeekWrite( unsigned int Pos )
		{
			Stream_.seekp( Pos );
		}
		void FiFSFile::SeekWrite( unsigned int Pos, FsSeekDir Dir )
		{
			std::ios::seekdir dir = std::ios::beg;
			if ( Dir == FsSeekDir::End )
				dir = std::ios::end;
			Stream_.seekp( Pos, dir );

		}

		void FiFSFile::Put( char C )
		{
			Stream_.put( C );
		}

		void FiFSFile::Write( const char* S, unsigned int Size )
		{
			Stream_.write( S, Size );
		}

		std::string FiFSFile::ReadAll()
		{
			std::string str;
			SeekRead( 0, FsSeekDir::End );
			str.reserve( ( int ) TellRead() );
			SeekRead( 0, FsSeekDir::Begin );


			str.assign( ( std::istreambuf_iterator<char>( Stream_ ) ),
						std::istreambuf_iterator<char>() );

			return str;

		}

		bool FiFSFile::IsOpen()
		{
			return Stream_.is_open();
		}

	}
}