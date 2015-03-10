#include "Bubblewrap/Render/ReColour.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		ReColour::ReColour( )
			: A_( ( char ) 0xFF ), R_( ( char ) 0xFF ), G_( ( char ) 0xFF ), B_( ( char ) 0xFF )
		{

		}
		ReColour::ReColour( unsigned int ARGB )
		{
			unsigned int A = ( 0xFF000000 & ARGB ) >> 24;
			unsigned int R = ( 0x00FF0000 & ARGB ) >> 16;
			unsigned int G = ( 0x0000FF00 & ARGB ) >> 8;
			unsigned int B = ( 0x000000FF & ARGB ) >> 0;
			R_ = ( char ) R;
			G_ = ( char ) G;
			B_ = ( char ) B;
			A_ = ( char ) A;
		}

		ReColour::ReColour( char R, char G, char B )
			: A_( (char)0xFF ), R_( R ), G_( G ), B_( B )
		{

		}

		ReColour::ReColour( char A, char R, char G, char B )
			: A_( A ), R_( R ), G_( G ), B_( B )
		{

		}

		ReColour::ReColour( float R, float G, float B )
			: A_( (char)0xFF ), R_( ( char ) ( R*255.0f ) ), G_( ( char ) ( G * 255.0f ) ), B_( ( char ) ( B * 255.0f ) )
		{

		}

		ReColour::ReColour( float A, float R, float G, float B )
			: A_( (char) (A * 255.0f) ), R_( ( char ) ( R*255.0f ) ), G_( ( char ) ( G * 255.0f ) ), B_( ( char ) ( B * 255.0f ) )
		{

		}
		char ReColour::R()
		{
			return R_;
		}

		char ReColour::G()
		{
			return G_;
		}
		char ReColour::B()
		{
			return B_;
		}
		char ReColour::A()
		{
			return A_;
		}

	}
}