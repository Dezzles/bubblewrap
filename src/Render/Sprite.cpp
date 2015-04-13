#include "Bubblewrap/Render/Sprite.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		Sprite::Sprite()
		{
			IsDirty_ = false;
			RenderItem_ = nullptr;
			Texture_ = nullptr;
		}

		void Sprite::Initialise( Json::Value Params )
		{
			Drawable::Initialise( Params );
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
				auto values = dynamic_cast<Texture*>( GetRegister().GetResource( TextureName_ ) );

				SetTexture( values );
			}
			RenderItem_ = (Render::Vertices*)GetRegister().CreateObject( std::string( "Vertices" ), GetParentEntity() );
			RenderItem_->Reserve( 4 );
			Vertex v;
			v.Colour_ = Colour_;
			v.Position_ = Math::Vector3f( -Size_.X() * 0.5f, -Size_.Y() * 0.5f, 0.0f );
			v.TexCoords_ = Math::Vector2f( 0.0f, 0.0f );
			RenderItem_->AddVertex( v );

			v.Colour_ = Colour_;
			v.Position_ = Math::Vector3f( Size_.X() * 0.5f, -Size_.Y() * 0.5f, 0.0f );
			v.TexCoords_ = Math::Vector2f( 1.0f, 0.0f );
			RenderItem_->AddVertex( v );

			v.Colour_ = Colour_;
			v.Position_ = Math::Vector3f( -Size_.X() * 0.5f, Size_.Y() * 0.5f, 0.0f );
			v.TexCoords_ = Math::Vector2f( 0.0f, 1.0f );
			RenderItem_->AddVertex( v );

			v.Colour_ = Colour_;
			v.Position_ = Math::Vector3f( Size_.X() * 0.5f, Size_.Y() * 0.5f, 0.0f );
			v.TexCoords_ = Math::Vector2f( 1.0f, 1.0f );
			RenderItem_->AddVertex( v );/**/
			RenderItem_->SetPrimitiveType( Render::Primitives::TrianglesStrip );
			RenderItem_->SetDrawOrder( DrawOrder_ );
			RenderItem_->SetTexture( Texture_ );
			RenderItem_->SetWindow( Window_ );
			RenderItem_->Refresh();
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
			Drawable::Update( dt );
		}

		void Sprite::SetTexture( Texture* Texture )
		{
			Texture_ = Texture;
			if ( RenderItem_ != nullptr )
				RenderItem_->SetTexture( Texture_ );
			IsDirty_ = true;
		}
	}
}