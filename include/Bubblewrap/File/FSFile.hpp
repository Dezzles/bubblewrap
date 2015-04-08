#ifndef FFSFILE_HPP
#define FIFSFILE_HPP

#include <string>
#include <fstream>
#include <streambuf>
#include "Bubblewrap/File/File.hpp"
namespace Bubblewrap
{
	namespace File
	{
		/*! Object used for reading files from the native file system using streams.
		*/
		class FSFile 
			: public File
		{
		public:
			/*! Sets the file to be loaded
			\param Filename The file to be loaded */
			FSFile( std::string Filename );
			~FSFile();
			virtual void Open( FileMode Mode );
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
			virtual void SeekRead( unsigned int Pos, SeekDir Dir );

			virtual void SeekWrite( unsigned int Pos );
			virtual void SeekWrite( unsigned int Pos, SeekDir Dir );

			virtual void Put( char C );

			virtual void Write( const char* S, unsigned int Size );

			virtual bool IsOpen();

			/*! Reads in all text in a file. Should only be used on non-binary files.
			\returns All text in a file.
			*/
			std::string ReadAll();

		private:
			std::fstream Stream_;
			std::string Filename_;
		};

	}
}




#endif