#include "Bubblewrap/Render/ReTexture.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		ReTexture::ReTexture()
		{

		}

		void ReTexture::Initialise( Json::Value Params )
		{
			GoBase::Initialise( Params );
			Texture_.loadFromFile( Params[ "texture" ].asString() );
			
		}

		void ReTexture::Copy( ReTexture* Target, ReTexture* Base )
		{
			Target->Texture_ = Base->Texture_;
		}

		void ReTexture::Update( float dt )
		{

		}

		sf::Texture* ReTexture::GetTexture()
		{
			return &Texture_;
		}
	}
}