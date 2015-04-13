#ifndef BUBBLEWRAP_RENDER_TEXT_HPP
#define BUBBLEWRAP_RENDER_TEXT_HPP

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
		/*! Used for rendering text onto the screen
		Text can have the following JSON parameters:
		- name /a Required - name of the sprite
		- colour /a Optional - a plain text description of a colour (e.g. "255 0 0")
		- size /a Optional - a plain text description of a Vector2 (e.g. "43.2 1.3")
		- position /a Optional - position relative to the parent entity
		- text /a Optional - the text to be displayed
		- fontName /a Optional - the font resource to be used for drawing
		- characterSize /a Optional - the size of the font to use
		- hAlign /a Optional - the horizontal alignment of the text
		- vAlign /a Optional - the vertical alignment of the text
		*/
		class Text
			: public Drawable
		{
		public:
			/*! Dictates horizontal alignment*/
			enum class HAlign
			{
				/*! Left alignment */
				Left, 
				/*! Centre alignment */
				Centre,
				/*! Right alignment */
				Right
			};
			/*! Dicates vertical alignment*/
			enum class VAlign
			{
				/*! Top alignment */
				Top,
				/*! Centre alignment */
				Centre,
				/*! Bottom alignment */
				Bottom
			};

			/*! Creates a Text object */
			Text();

			/*! Initialises a Text object
			\param Params A Json value containing the data to initialise the text with
			*/
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Text );

			/*! Updates the Text with timestep dt in seconds
			*/
			virtual void Update( float dt );

			/*! Attempts to get a Font resource using Font name
			*/
			virtual void OnAttach();

			/*! Gets the colour of the text
			\returns The colour of the text
			*/
			Colour GetColour();
			/*! Sets the colour of the text
			\param Colour The new colour of the text
			*/
			void SetColour( Colour Colour );

			/*! Gets the size of the text rendering area
			\returns The size of the text rendering area
			*/
			Math::Vector2f GetSize();
			
			/*! Sets the size of the text rendering area
			\param Size The new size of the text rendering area
			*/
			void SetSize( Math::Vector2f Size );

			/*! Gets the position of the text
			\returns The position of the text relative to its parent
			*/
			Math::Vector2f GetPosition();
			
			/*! Sets the position of the text
			\param Val The position of the text relative to its parent 
			*/
			void SetPosition( Math::Vector2f Val );

			/*! Gets the current text that will be rendered
			\returns The current text to render 
			*/
			std::string GetText();
			
			/*! Sets new text that should be rendered
			\param Text New text to render
			*/
			void SetText( std::string Text );

			/*! Gets the name of the font resource to render with
			\returns The name of the font resource to render with
			*/
			std::string GetFontName();

			/*! Sets the name of the font resource to render with 
			\param FontName The name of the new font resource to render with*/
			void SetFontName( std::string FontName );

			/*! Sets the font resource to be rendered with
			\param Font new font to render with
			*/
			void SetFont( Font* Font );

			/*! Gets that character size used to draw the text
			\returns The current character size 
			*/
			int GetCharacterSize();

			/*! Sets the character size for the text 
			\param CharacterSize The new size for character rendering 
			*/
			void SetCharacterSize( int CharacterSize );

			/*! Gets the current horizontal alignment
			\return Horizontal alignment
			*/
			HAlign GetHorizontalAlignment();
			
			/*! Sets the horizontal alignment
			\param Align The new horizontal alignment
			*/
			void SetHorizontalAlignment( HAlign Align );
			
			/*! Gets the current vertical alignment
			\return Vertical alignment 
			*/
			VAlign GetVerticalAlignment();
			
			/*! Sets the vertical alignment
			\param Align The new vertical alignment 
			*/
			void SetVerticalAlignment( VAlign Align );
		protected:
			/*! Current position relative to the parent */
			Math::Vector2f Position_;
			/*! Size of the area in which the text should be rendered */
			Math::Vector2f Size_;
			/*! Colour that the text should be rendered as*/
			Colour Colour_;
			/*! Marks when values have changed */
			bool IsDirty_;
			/*! The text that should be rendered */
			std::string Text_;
			/*! The name of the font resource that should be used */
			std::string FontName_;
			/*! The size used to render that font */
			int CharacterSize_;
			/*! The Font resource that should be used to render the Text */
			Font* Font_;
			/*! The horizontal alignment of the text */
			HAlign HorizontalAlignment_;
			/*! The vertical alignment of the text */
			VAlign VerticalAlignment_;
		};
	}
}




#endif