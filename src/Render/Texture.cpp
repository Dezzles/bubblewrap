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
			GoBase::Initialise( Params );
			
		}

		void Texture::Copy( Texture* Target, Texture* Base )
		{
			Component::Copy( Target, Base );
		}

		void Texture::Update( float dt )
		{

		}

	}
}