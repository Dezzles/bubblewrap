#ifndef FFSFILE_HPP
#define FIFSFILE_HPP

#include <string>
#include <fstream>
#include <streambuf>
#include "Bubblewrap/File/FiFile.hpp"
namespace Bubblewrap
{
	namespace File
	{
		class FiFSFile 
			: public FiFile
		{
		public:
			FiFSFile( std::string Filename );
			~FiFSFile();
			virtual void Open( FsMode Mode );
			virtual void Close();

			virtual int Get();
			virtual void Get( char& C );
			virtual void Get( char* S, unsigned int Size );
			virtual void Get( char* S, unsigned int Size, char Delim );

			virtual void GetLine( char* S, unsigned int Size );
			virtual void GetLine( char* S, unsigned int Size, char Delim );

			virtual int Peek();

			virtual void Read( char* S, unsigned int Size );

			virtual unsigned int TellRead();
			virtual unsigned int TellWrite();

			virtual void SeekRead( unsigned int Pos );
			virtual void SeekRead( unsigned int Pos, FsSeekDir Dir );

			virtual void SeekWrite( unsigned int Pos );
			virtual void SeekWrite( unsigned int Pos, FsSeekDir Dir );

			virtual void Put( char C );

			virtual void Write( const char* S, unsigned int Size );

			virtual bool IsOpen();
			std::string ReadAll();

		private:
			std::fstream Stream_;
			std::string Filename_;
		};

	}
}




#endif