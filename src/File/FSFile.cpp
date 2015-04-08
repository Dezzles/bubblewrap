#include "Bubblewrap/File/FSFile.hpp"

namespace Bubblewrap
{
	namespace File
	{
		FSFile::FSFile( std::string Filename )
			: Filename_( Filename )
		{
		}
		FSFile::~FSFile()
		{
		}

		void FSFile::Open( FileMode Mode )
		{
			std::ios_base::open_mode mode = 0;

			if ( Is( Mode, FileMode::Read ) )
				mode = mode | std::ios::in;
			if ( Is( Mode, FileMode::Write ) )
				mode = mode | std::ios::out;
			if ( Is( Mode, FileMode::Binary ) )
				mode = mode | std::ios::binary;

			Stream_.open( Filename_.c_str(), mode );
		}

		void FSFile::Close()
		{
			Stream_.close();
		}

		int FSFile::Get()
		{
			return Stream_.get();
		}
		void FSFile::Get( char& C )
		{
			Stream_.get( C );
		}
		void FSFile::Get( char* S, unsigned int Size )
		{
			Stream_.get( S, Size );
		}
		void FSFile::Get( char* S, unsigned int Size, char Delim )
		{
			Stream_.get( S, Size, Delim );
		}

		void FSFile::GetLine( char* S, unsigned int Size )
		{
			Stream_.getline( S, Size );
		}
		void FSFile::GetLine( char* S, unsigned int Size, char Delim )
		{
			Stream_.getline( S, Size, Delim );
		}

		int FSFile::Peek()
		{
			return Stream_.peek();
		}

		void FSFile::Read( char* S, unsigned int Size )
		{
			Stream_.read( S, Size );
		}

		unsigned int FSFile::TellRead()
		{
			return static_cast< unsigned int >( Stream_.tellg() );
		}

		unsigned int FSFile::TellWrite()
		{
			return static_cast< unsigned int >( Stream_.tellp() );
		}

		void FSFile::SeekRead( unsigned int Pos )
		{
			Stream_.seekg( Pos );
		}

		void FSFile::SeekRead( unsigned int Pos, SeekDir Dir )
		{
			std::ios::seekdir dir = std::ios::beg;
			if ( Dir == SeekDir::End )
				dir = std::ios::end;
			Stream_.seekg( Pos, dir );
		}

		void FSFile::SeekWrite( unsigned int Pos )
		{
			Stream_.seekp( Pos );
		}
		void FSFile::SeekWrite( unsigned int Pos, SeekDir Dir )
		{
			std::ios::seekdir dir = std::ios::beg;
			if ( Dir == SeekDir::End )
				dir = std::ios::end;
			Stream_.seekp( Pos, dir );

		}

		void FSFile::Put( char C )
		{
			Stream_.put( C );
		}

		void FSFile::Write( const char* S, unsigned int Size )
		{
			Stream_.write( S, Size );
		}

		std::string FSFile::ReadAll()
		{
			std::string str;
			SeekRead( 0, SeekDir::End );
			str.reserve( ( int ) TellRead() );
			SeekRead( 0, SeekDir::Begin );


			str.assign( ( std::istreambuf_iterator<char>( Stream_ ) ),
						std::istreambuf_iterator<char>() );

			return str;

		}

		bool FSFile::IsOpen()
		{
			return Stream_.is_open();
		}

	}
}