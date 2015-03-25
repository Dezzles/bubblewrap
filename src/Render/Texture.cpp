#include "Bubblewrap/Render/Texture.hpp"
#include "Bubblewrap/Base/Component.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		Texture::Texture()
		{

		}

		void Texture::Initialise( Json::Value Params )
		{
			Resource::Initialise( Params );
			
		}

		void Texture::Copy( Texture* Target, Texture* Base )
		{
			Resource::Copy( Target, Base );
		}

		void Texture::Update( float dt )
		{

		}

	}
}