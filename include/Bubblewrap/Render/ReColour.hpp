#ifndef RECOLOUR_HPP
#define RECOLOUR_HPP

namespace Bubblewrap
{
	namespace Render
	{
		class ReColour
		{
		public:
			ReColour();
			ReColour( unsigned int ARGB );
			ReColour( char R, char G, char B );
			ReColour( char A, char R, char G, char B );
			ReColour( float R, float G, float B );
			ReColour( float A, float R, float G, float B );

			char R();
			char G();
			char B();
			char A();

		private:
			char R_;
			char G_;
			char B_;
			char A_;

		};
	}
}


#endif