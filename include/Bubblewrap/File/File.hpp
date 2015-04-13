#ifndef BUBBLEWRAP_FILE_FILE_HPP
#define BUBBLEWRAP_FILE_FILE_HPP

#include <string>
#include <fstream>
#include <streambuf>

namespace Bubblewrap
{
	namespace File
	{
		/*! Indicates whether File seek should be from the beginning or end of a file */
		enum class SeekDir
		{
			/*! Seek from beginning of file. */
			Begin,
			/*! Seek from the end of the file. */
			End
		};

		/*! Indicates the mode with which the file should be loaded */
		enum class FileMode
		{
			/*! The file should be opened for reading. */
			Read = 1,
			/*! The file should be opened for writing. */
			Write = 2,
			/*! The file should be opened for both reading and writing. */
			ReadWrite = 1 | 2,
			/*! The file should be opened as a binary file. */
			Binary = 4
		};

		/*! Interface for creating file streams */
		class File
		{
		public:
			/*! Compares to see if two FileModes match any types 
			\param l The first Filemode
			\param r The second Filemode
			\returns true if they share any types
			*/
			static bool Is( FileMode l, FileMode r )
			{
				return ( (int)l & (int)r ) != 0;
			}

			/*! Opens the file 
			\param Mode The mode that the file will open in
			*/
			virtual void Open( FileMode Mode ) = 0;
			/*! Closes the file */
			virtual void Close() = 0;
			
			/*! Gets a character from the file
			\returns The next character in the file stream
			*/
			virtual int Get() = 0;
			/*! Gets the next character in the file stream
			\param C The char that the character should be placed in
			\retval C The next character is stored here 
			*/
			virtual void Get( char& C ) = 0;
			/*! Gets characters from the stream
			\param Size the number of characters to read in
			\param S Pointer to a character array of minimum size Size
			\retval S An array filled with up to Size characters from the file.
			*/
			virtual void Get( char* S, unsigned int Size ) = 0;
			/*! Gets characters from the stream until it encounters Delim or reaches Size characters
			\param S Pointer to a character array of minimum size Size
			\param Size the number of characters to read in
			\param Delim The delimiter that we should read until it is found
			\retval S An array filled with up to Size characters from the file.
			*/
			virtual void Get( char* S, unsigned int Size, char Delim ) = 0;
			
			/*! Gets characters from the stream until it encounters a new line or reaches Size characters
			\param S Pointer to a character array of minimum size Size
			\param Size the number of characters to read in
			\retval S An array filled with up to Size characters from the file.
			*/
			virtual void GetLine( char* S, unsigned int Size ) = 0;

			/*! Gets characters from the stream until it encounters Delim or reaches Size characters
			\param S Pointer to a character array of minimum size Size
			\param Size the number of characters to read in
			\param Delim The delimiter that we should read until it is found
			\retval S An array filled with up to Size characters from the file.
			*/
			virtual void GetLine( char* S, unsigned int Size, char Delim ) = 0;

			/*! Gets the next character but doesn't move the location in the file. 
			\returns the next character in the stream.
			*/
			virtual int Peek() = 0;

			/*! Gets characters from the stream until it encounters EOF or reaches Size characters
			\param S Pointer to a character array of minimum size Size
			\param Size the number of characters to read in
			\retval S An array filled with up to Size characters from the file.
			*/
			virtual void Read( char* S, unsigned int Size ) = 0;

			/*! Gets the current location of the Read marker
			\retval The current location in the file of the read marker
			*/
			virtual unsigned int TellRead() = 0;

			/*! Gets the current location of the write marker
			\retval The current location in the file of the write marker
			*/
			virtual unsigned int TellWrite() = 0;

			/*! Sets the current location of the read marker
			\param Pos The new position of the read marker 
			*/
			virtual void SeekRead( unsigned int Pos ) = 0;

			/*! Sets the current location of the read marker
			\param Pos The new position of the read marker
			\param Dir Whether to count from the beginning or end of file
			*/
			virtual void SeekRead( unsigned int Pos, SeekDir Dir ) = 0;

			/*! Sets the current location of the write marker
			\param Pos The new position of the write marker
			*/
			virtual void SeekWrite( unsigned int Pos ) = 0;

			/*! Sets the current location of the write marker
			\param Pos The new position of the write marker
			\param Dir Whether to count from the beginning or end of file
			*/
			virtual void SeekWrite( unsigned int Pos, SeekDir Dir ) = 0;

			/*! Places a character into the file at the current write marker
			\param C The character to place into the file 
			*/
			virtual void Put( char C ) = 0;

			/*! Writes characters into the file at the current write marker
			\param S An array of characters to write into the file
			\param Size The number of characters to write into the file 
			*/
			virtual void Write( const char* S, unsigned int Size ) = 0;

			/*! Indicates whether the file is open */
			virtual bool IsOpen() = 0;
		private:
		};

	}
}




#endif