#ifndef Colour_HPP
#define Colour_HPP

#include <string>

namespace Bubblewrap
{
	namespace Render
	{
		/*! Defines colours used throughout Bubblewrap.
			You're welcome to complain that I use the one true spelling of Colour.
			Your complaints will be ignored.*/
		class Colour
		{
		public:
			/*! Creates a default colour. Probably black.
			*/
			Colour();
			/*! Creates a colour using an ARGB integer.
			\param ARGB Stores the ARGB values with 1 byte per channel.
			*/
			Colour( unsigned int ARGB );
			/*! Creates a new Colour
			\param R The red component in the range 0 - 255
			\param G The green component in the range 0 - 255
			\param B The blue component in the range 0 - 255
			*/
			Colour( unsigned char R, unsigned char G, unsigned char B );
			/*! Creates a new Colour
			\param A The alpha component in the range 0 - 255
			\param R The red component in the range 0 - 255
			\param G The green component in the range 0 - 255
			\param B The blue component in the range 0 - 255
			*/
			Colour( unsigned char R, unsigned char G, unsigned char B, unsigned char A );
			/*! Creates a new Colour
			\param R The red component in the range 0.0 - 1.0
			\param G The green component in the range 0.0 - 1.0
			\param B The blue component in the range 0.0 - 1.0
			*/
			Colour( float R, float G, float B );
			/*! Creates a new Colour
			\param A The alpha component in the range 0.0 - 1.0
			\param R The red component in the range 0.0 - 1.0
			\param G The green component in the range 0.0 - 1.0
			\param B The blue component in the range 0.0 - 1.0
			*/
			Colour( float R, float G, float B, float A );

			/*! Creates a new Colour from a string
			\param Colour The colour in string format of "R G B A" where A is optional and all values should be in the range 0 - 255.
			*/
			Colour( std::string Colour );

			/*! Gets the R component
			\returns The R component of the colour
			*/
			unsigned char R();
			/*! Gets the G component
			\returns The G component of the colour
			*/
			unsigned char G();
			/*! Gets the B component
			\returns The B component of the colour
			*/
			unsigned char B();
			/*! Gets the A component
			\returns The A component of the colour
			*/
			unsigned char A();

		private:
			unsigned char R_;
			unsigned char G_;
			unsigned char B_;
			unsigned char A_;

		};
	}
}


#endif