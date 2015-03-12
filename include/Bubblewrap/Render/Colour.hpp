#ifndef Colour_HPP
#define Colour_HPP

#include <string>

namespace Bubblewrap
{
	namespace Render
	{
		class Colour
		{
		public:
			Colour();
			Colour( unsigned int ARGB );
			Colour( unsigned char R, unsigned char G, unsigned char B );
			Colour( unsigned char A, unsigned char R, unsigned char G, unsigned char B );
			Colour( float R, float G, float B );
			Colour( float A, float R, float G, float B );
			Colour::Colour( std::string Colour );

			unsigned char R();
			unsigned char G();
			unsigned char B();
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