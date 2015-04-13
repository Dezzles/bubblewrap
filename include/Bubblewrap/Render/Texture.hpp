#ifndef BUBBLEWRAP_RENDER_TEXTURE_HPP
#define BUBBLEWRAP_RENDER_TEXTURE_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Resource.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		/*! Used for storing Textures
		*/
		class Texture
			: public Base::Resource
		{
		public:
			/*! Creates a Texture
			*/
			Texture();
			/*! Initialises a Texture object
			\param Params A Json value containing the data to initialise the texture with
			*/
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Texture );
		};
	}
}


#endif