#ifndef BUBBLEWRAP_TEXT_HPP
#define BUBBLEWRAP_TEXT_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/Drawable.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Render/Colour.hpp"
#include "Bubblewrap/Render/Window.hpp"
#include "Bubblewrap/Render/Font.hpp"
namespace Bubblewrap
{
	namespace Render
	{

		class Text
			: public Drawable
		{
		public:
			enum class HAlign
			{
				Left, Centre, Right
			};
			enum class VAlign
			{
				Top, Centre, Bottom
			};
			Text();
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Text );

			virtual void Update( float dt );
			virtual void OnAttach();


			Colour GetColour();
			void SetColour( Colour Colour );

			Math::Vector2f GetSize();
			void SetSize( Math::Vector2f Size );

			Math::Vector2f GetPosition();
			void SetPosition( Math::Vector2f Val );

			std::string GetText();
			void SetText( std::string Text );

			std::string GetFontName();
			void SetFontName( std::string FontName );

			int GetCharacterSize();
			void SetCharacterSize( int CharacterSize );

			HAlign GetHorizontalAlignment();
			void SetHorizontalAlignment( HAlign Align );

			VAlign GetVerticalAlignment();
			void SetVerticalAlignment( VAlign Align );
		protected:
			Math::Vector2f Position_;
			Math::Vector2f Size_;
			Colour Colour_;
			bool IsDirty_;
			std::string Text_;
			std::string FontName_;
			int CharacterSize_;
			Font* Font_;
			HAlign HorizontalAlignment_;
			VAlign VerticalAlignment_;
		};
	}
}




#endif