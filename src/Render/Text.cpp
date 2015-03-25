#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Render/Text.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		Text::Text()
		{
			IsDirty_ = false;
			Font_ = nullptr;
		}

		void Text::Initialise( Json::Value Params )
		{
			Drawable::Initialise( Params );
			SetSize( Math::Vector2f( Params[ "size" ].asString() ) );
			SetPosition( Math::Vector2f( Params[ "position" ].asString() ) );
			SetColour( Render::Colour( Params[ "colour" ].asString() ) );
			SetFontName( Params[ "font" ].asString() );
			SetText( Params[ "text" ].asString() );
			SetCharacterSize( Params[ "characterSize" ].asInt() );
		}


		void Text::Copy( Text* Target, Text* Base )
		{
			Drawable::Copy( Target, Base );
			Target->SetSize( Base->Size_ );
			Target->SetColour( Base->Colour_ );
			Target->SetPosition( Base->Position_ );
			Target->SetText( Base->Text_ );
			Target->SetFontName( Base->FontName_ );
			Target->SetCharacterSize( Base->CharacterSize_ );
		}

		void Text::OnAttach()
		{
			Font_ = dynamic_cast<Font*>( GetRegister().GetResource( FontName_ ) );
		}


		Math::Vector2f Text::GetSize()
		{
			return Size_;
		}

		void Text::SetSize( Math::Vector2f Size )
		{
			Size_ = Size;
			IsDirty_ = true;
		}

		Colour Text::GetColour()
		{
			return Colour_;
		}

		void Text::SetColour( Colour Colour )
		{
			Colour_ = Colour;
			IsDirty_ = true;
		}

		void Text::Update( float dt )
		{
			Drawable::Update( dt );
		}

		Math::Vector2f Text::GetPosition()
		{
			return Position_;
		}

		void Text::SetPosition( Math::Vector2f Val )
		{
			Position_ = Val;
			IsDirty_ = true;
		}

		std::string Text::GetText()
		{
			return Text_;
		}

		void Text::SetText( std::string Text )
		{
			Text_ = Text;
			IsDirty_ = true;
		}

		std::string Text::GetFontName()
		{
			return FontName_;
		}

		void Text::SetFontName( std::string FontName )
		{
			FontName_ = FontName;
		}

		int Text::GetCharacterSize()
		{
			return CharacterSize_;
		}

		void Text::SetCharacterSize( int CharacterSize )
		{
			CharacterSize_ = CharacterSize;
			IsDirty_ = true;
		}
	}
}