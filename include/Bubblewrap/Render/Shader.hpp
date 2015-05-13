#ifndef BUBBLEWRAP_RENDER_SHADER_HPP
#define BUBBLEWRAP_RENDER_SHADER_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Resource.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		/*! Used for storing Textures
		*/
		class Shader
			: public Base::Resource
		{
		public:
			/*! Creates a Texture
			*/
			Shader();
			/*! Initialises a Texture object
			\param Params A Json value containing the data to initialise the texture with
			*/
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Shader );
		};
	}
}


#endif