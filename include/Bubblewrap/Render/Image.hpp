#ifndef BUBBLEWRAP_RENDER_IMAGE_HPP
#define BUBBLEWRAP_RENDER_IMAGE_HPP

#include "Bubblewrap/Base.hpp"
#include "Bubblewrap/Render/Colour.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		class Image 
			: public Base::Resource
		{
		public:
			/*! Creates an Image
			*/
			Image();
			/*! Initialises and Image object
			\param Params A Json value containing the data to initialise the image with
			*/
			void Initialise( Json::Value Params );

			/*! Gets the colour at a given pixel
			\param X The horizontal coordinate of a pixel
			\param Y The vertical coordinate of a pixel
			\returns The pixel colour at (X,Y) or black if coordinates are invalid.
			*/
			Colour GetColour( int X, int Y );

			/*! Gets the width of the Image
			\return The width of the image, or -1 if an error occurs
			*/
			virtual int GetWidth();

			/*! Gets the height of the Image
			\return The height of the image, or -1 if an error occurs
			*/
			virtual int GetHeight();

			CREATE_REGISTER( Image );

			PROTECTED_FIELD( std::string, Filename );


		};
	}
}




#endif