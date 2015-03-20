#include "Bubblewrap/Render/Sprite.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		Sprite::Sprite()
		{
			IsDirty_ = false;
		}

		void Sprite::Initialise( Json::Value Params )
		{
			SetWindow( Params[ "window" ].asString() );
			SetSize( Math::Vector2f( Params[ "size" ][ "x" ].asFloat(), Params[ "size" ][ "y" ].asFloat() ) );
			TextureName_ = "";
			if ( !Params[ "texture" ].isNull() )
				TextureName_ = Params[ "texture" ].asString();
		}


		void Sprite::Copy( Sprite* Target, Sprite* Base )
		{
			Drawable::Copy( Target, Base );
			Target->SetSize( Base->Size_ );
			Target->TextureName_ = Base->TextureName_;
			Target->Texture_ = Base->Texture_;
			Target->SetColour( Base->Colour_ );

		}

		void Sprite::OnAttach()
		{
			if ( TextureName_ != "" )
			{
				auto values = GetParentEntity()->GetComponentsByType<Texture>( TextureName_ );

				if ( values.size() > 0 )
				{
					SetTexture( values[ 0 ] );
				}
			}
		}


		Math::Vector2f Sprite::GetSize()
		{
			return Size_;
		}

		void Sprite::SetSize( Math::Vector2f Size )
		{
			Size_ = Size;
			IsDirty_ = true;
		}

		Colour Sprite::GetColour()
		{
			return Colour_;
		}

		void Sprite::SetColour( Colour Colour )
		{
			Colour_ = Colour;
			IsDirty_ = true;
		}

		void Sprite::Update( float dt )
		{
			Math::Vector2f Position = GetParentEntity()->WorldPosition();
		}

		void Sprite::SetTexture( Texture* Texture )
		{
			Texture_ = Texture;
		}
	}
}