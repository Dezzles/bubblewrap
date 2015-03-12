#include "Bubblewrap/Render/Colour.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		Colour::Colour( )
			: A_( ( unsigned char ) 0xFF ), R_( ( unsigned char ) 0xFF ), G_( ( unsigned char ) 0xFF ), B_( ( unsigned char ) 0xFF )
		{

		}

		Colour::Colour( std::string Colour )
		{
			int R, G, B, A;
			A = 255;
			int Idx1 = Colour.find_first_of( ' ' );
			int Idx2 = Colour.find_first_of( ' ', Idx1 + 1 );
			int Idx3 = Colour.find_first_of( ' ', Idx2 + 1 );
			std::string sR = Colour.substr( 0, Idx1 );
			std::string sG = Colour.substr( Idx1 + 1, Idx2 - Idx1 );
			int p3 = std::string::npos;
			if ( Idx3 != std::string::npos )
				p3 = Idx3 - Idx2;
			std::string sB = Colour.substr( Idx2 + 1, p3 );
			if ( Idx3 != std::string::npos )
			{
				std::string sA = Colour.substr( Idx3 + 1 );
				A = atoi( sA.c_str() );
			}
			R = atoi( sR.c_str() );
			G = atoi( sG.c_str() );
			B = atoi( sB.c_str() );

			A_ = ( unsigned char )A;
			G_ = ( unsigned char ) G;
			B_ = ( unsigned char ) B;
			R_ = ( unsigned char ) R;
		}

		Colour::Colour( unsigned int ARGB )
		{
			unsigned int A = ( 0xFF000000 & ARGB ) >> 24;
			unsigned int R = ( 0x00FF0000 & ARGB ) >> 16;
			unsigned int G = ( 0x0000FF00 & ARGB ) >> 8;
			unsigned int B = ( 0x000000FF & ARGB ) >> 0;
			R_ = ( unsigned char ) R;
			G_ = ( unsigned char ) G;
			B_ = ( unsigned char ) B;
			A_ = ( unsigned char ) A;
		}

		Colour::Colour( unsigned char R, unsigned char G, unsigned char B )
			: A_( (unsigned char)0xFF ), R_( R ), G_( G ), B_( B )
		{

		}

		Colour::Colour( unsigned char A, unsigned char R, unsigned char G, unsigned char B )
			: A_( A ), R_( R ), G_( G ), B_( B )
		{

		}

		Colour::Colour( float R, float G, float B )
			: A_( (unsigned char)0xFF ), R_( ( unsigned char ) ( R*255.0f ) ), G_( ( unsigned char ) ( G * 255.0f ) ), B_( ( unsigned char ) ( B * 255.0f ) )
		{

		}

		Colour::Colour( float A, float R, float G, float B )
			: A_( (unsigned char) (A * 255.0f) ), R_( ( unsigned char ) ( R*255.0f ) ), G_( ( unsigned char ) ( G * 255.0f ) ), B_( ( unsigned char ) ( B * 255.0f ) )
		{

		}
		unsigned char Colour::R()
		{
			return R_;
		}

		unsigned char Colour::G()
		{
			return G_;
		}
		unsigned char Colour::B()
		{
			return B_;
		}
		unsigned char Colour::A()
		{
			return A_;
		}

	}
}