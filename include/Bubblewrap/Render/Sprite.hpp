#ifndef BUBBLEWRAP_RENDER_SPRITE_HPP
#define BUBBLEWRAP_RENDER_SPRITE_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/Drawable.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Render/Colour.hpp"
#include "Bubblewrap/Render/Window.hpp"
#include "Bubblewrap/Render/Texture.hpp"
#include "Bubblewrap/Render/Vertices.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		/*! Sprites are used for drawing positioned 
		A sprite can have the following JSON parameters:
		- name /a Required - name of the sprite
		- colour /a Optional - a plain text description of a colour (e.g. "255 0 0")
		- size /a Optional - a plain text description of a Vector2 (e.g. "43.2 1.3")
		- texture /a Optional - the name of the texture resource to use
		*/
		class Sprite
			: public Drawable
		{
		public:
			/*! Creates a sprite object 
			*/
			Sprite();
			
			/*! Initialises a sprite
			\param Params A Json value containing the data to initialise the sprite with
			*/
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Sprite );

			/*! Updates the sprite with timestep dt in seconds 
			*/
			virtual void Update( float dt );

			/*! Will attempt to load get a Texture resource if texture was set at load time*/
			virtual void OnAttach();

			/*! Gets the current colour set to the sprite
			\returns Sprite colour
			*/
			Colour GetColour();
			/*! Sets a new colour to the sprite
			\param Colour the colour to be set
			*/
			void SetColour( Colour Colour );

			/*! Gets the size of the sprite
			\returns Sprite size
			*/
			Math::Vector2f GetSize();
			
			/*! Sets the size of the sprite
			\param Size The new size for the sprite 
			*/
			void SetSize( Math::Vector2f Size );

			/*! Sets the texture to be used
			\param Texture A pointer to the new texture to be used
			*/
			void SetTexture( Texture* Texture );

		protected:
			/*! The size of the sprite. */
			Math::Vector2f Size_;

			/*! The colour of the sprite. */
			Colour Colour_;

			/*! The texture, if any, used while rendering the sprite. */
			Texture* Texture_;

			/*! The name of the texture resource used for rendering the sprite. */
			std::string TextureName_;

			/*! Marks whether any settings have been changed. */
			bool IsDirty_;

			Vertices* RenderItem_;
		};
	}
}


#endif