#ifndef RECOLOUR_HPP
#define RECOLOUR_HPP

#include <string>

namespace Bubblewrap
{
	namespace Render
	{
		class ReColour
		{
		public:
			ReColour();
			ReColour( unsigned int ARGB );
			ReColour( unsigned char R, unsigned char G, unsigned char B );
			ReColour( unsigned char A, unsigned char R, unsigned char G, unsigned char B );
			ReColour( float R, float G, float B );
			ReColour( float A, float R, float G, float B );
			ReColour::ReColour( std::string Colour );

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