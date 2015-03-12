#include "Bubblewrap/Render/Texture.hpp"

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
			Texture_.loadFromFile( Params[ "texture" ].asString() );
			
		}

		void Texture::Copy( Texture* Target, Texture* Base )
		{
			Target->Texture_ = Base->Texture_;
		}

		void Texture::Update( float dt )
		{

		}

		sf::Texture* Texture::GetTexture()
		{
			return &Texture_;
		}
	}
}