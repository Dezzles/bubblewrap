#ifndef FIFILE_HPP
#define FIFILE_HPP

#include <string>
#include <fstream>
#include <streambuf>

namespace Bubblewrap
{
	namespace File
	{
		enum class FsSeekDir
		{
			Begin,
			End
		};

		enum class FsMode
		{
			Read = 1,
			Write = 2,
			ReadWrite = 1 | 2,
			Binary = 4
		};

		class FiFile
		{
		public:
			static bool Is( FsMode l, FsMode r )
			{
				return ( (int)l & (int)r ) != 0;
			}

			virtual void Open( FsMode Mode ) = 0;
			virtual void Close() = 0;
			
			virtual int Get() = 0;
			virtual void Get( char& C ) = 0;
			virtual void Get( char* S, unsigned int Size ) = 0;
			virtual void Get( char* S, unsigned int Size, char Delim ) = 0;
			
			virtual void GetLine( char* S, unsigned int Size ) = 0;
			virtual void GetLine( char* S, unsigned int Size, char Delim ) = 0;

			virtual int Peek() = 0;

			virtual void Read( char* S, unsigned int Size ) = 0;

			virtual unsigned int TellRead() = 0;
			virtual unsigned int TellWrite() = 0;

			virtual void SeekRead( unsigned int Pos ) = 0;
			virtual void SeekRead( unsigned int Pos, FsSeekDir Dir ) = 0;

			virtual void SeekWrite( unsigned int Pos ) = 0;
			virtual void SeekWrite( unsigned int Pos, FsSeekDir Dir ) = 0;

			virtual void Put( char C ) = 0;

			virtual void Write( const char* S, unsigned int Size ) = 0;

			virtual bool IsOpen() = 0;
		private:
		};

	}
}




#endif