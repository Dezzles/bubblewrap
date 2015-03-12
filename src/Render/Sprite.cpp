#include "Bubblewrap/Render/ReSprite.hpp"
#include "Bubblewrap/Base/GoEntity.hpp"
#include "Bubblewrap/Base/GoBase.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		ReSprite::ReSprite()
		{
		}

		void ReSprite::Initialise( Json::Value Params )
		{
			SetWindow( Params[ "window" ].asString() );
			SetSize( Math::Vector2f( Params[ "size" ][ "x" ].asFloat(), Params[ "size" ][ "y" ].asFloat() ) );
			Shape_.setFillColor( sf::Color::White );
			TextureName_ = "";
			if ( !Params[ "texture" ].isNull() )
				TextureName_ = Params[ "texture" ].asString();
		}


		void ReSprite::Copy( ReSprite* Target, ReSprite* Base )
		{
			ReDrawable::Copy( Target, Base );
			Target->SetSize( Base->Size_ );
			Target->TextureName_ = Base->TextureName_;
			Target->Texture_ = Base->Texture_;
			Target->SetColour( Base->Colour_ );

		}

		void ReSprite::OnAttach()
		{
			if ( TextureName_ != "" )
			{
				auto values = GetParentEntity()->GetComponentsByType<ReTexture>( TextureName_ );
				assert( values.size() == 1 );
				if ( values.size() > 0 )
				{
					SetTexture( values[ 0 ] );
				}
			}
		}


		Math::Vector2f ReSprite::GetSize()
		{
			return Size_;
		}

		void ReSprite::SetSize( Math::Vector2f Size )
		{
			Size_ = Size;
			Shape_.setSize( sf::Vector2f( Size.X(), Size.Y() ) );
			Shape_.setOrigin( Size.X() * 0.5f, Size.Y() * 0.5f );
		}

		ReColour ReSprite::GetColour()
		{
			return Colour_;
		}

		void ReSprite::SetColour( ReColour Colour )
		{
			Colour_ = Colour;
			Shape_.setFillColor( sf::Color( Colour.R(), Colour.G(), Colour.B(), Colour.A() ) );
		}

		void ReSprite::Update( float dt )
		{
			Math::Vector2f Position = GetParentEntity()->WorldPosition();
			Shape_.setPosition( Position.X(), Position.Y() );
			sf::RectangleShape* shape = &Shape_;
			if ( Window_ != nullptr )
			{
				Window_->GetWindow<sf::RenderWindow>()->draw( Shape_ );
			}
		}

		void ReSprite::SetTexture( ReTexture* Texture )
		{
			Texture_ = Texture;
			Shape_.setTexture( Texture->GetTexture() );
		}
	}
}