#include "Bubblewrap/Render/Image.hpp"
#include "Bubblewrap/Base/Component.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		Image::Image()
		{

		}

		void Image::Initialise( Json::Value Params )
		{
			Resource::Initialise( Params );
			
			REQUIRED_LOAD( String, Filename, filename );
		}

		void Image::Copy( Image* Target, Image* Base )
		{
			Resource::Copy( Target, Base );
		}

		Colour Image::GetColour( int X, int Y )
		{
			return Colour( 1.0f , 1.0f , 1.0f , 1.0f );
		}

		int Image::GetWidth()
		{
			return -1;
		}

		int Image::GetHeight()
		{
			return -1;
		}

	}
}