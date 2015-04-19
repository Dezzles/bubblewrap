#ifndef BUBBLEWRAP_RENDER_VERTICES_HPP
#define BUBBLEWRAP_RENDER_VERTICES_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/Drawable.hpp"
#include "Bubblewrap/Render/Types.hpp"
#include "Bubblewrap/Base/Base.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		class Texture;
		/*! Renders sets of vertices 
		Vertices can have the following JSON parameters:
		- primitiveType /a Optional - name of the sprite
		- vertices /a Required - A json array of vertices with the following items
			- colour /a Required - The colour of the vertex in text format (i.e. "255 43 10 34" )
			- position /a Required - The position of the vertex in text format (i.e. "43.2 12.5 0.0" )
			- texCoords /a Required - The UV or texture coordinates of the vertex in text format (i.e "0.34 1.0" )
		*/
		class Vertices
			: public Drawable
		{
		public:
			/*! Creates the vertices object */
			Vertices();
			/*! Destroys the vertices object */
			~Vertices();
			/*! Initialises a Vertices object
			\param Params A Json value containing the data to initialise the vertices with
			*/
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Vertices );

			/*! Updates the vertices with timestep dt in seconds. This will attempt to grab the window if one has not been set. 
			\param dt The timestep in seconds
			*/
			virtual void Update( float dt );

			/*! Adds a Vertex to the vertices list 
			\param V The vertex to be added */
			int AddVertex( Vertex V );
			
			/*! Reserves memory for the vertex list 
			\param Amount The amound of additional memory to reserve 
			*/
			void Reserve( unsigned int Amount );

			/*! Sets a vertex in the list
			\param Idx The index of the vertex that is being set
			\param V The new vertext to be placed at a location in the list 
			*/
			void SetVertex( unsigned int Idx, Vertex V );
			
			/*! Unimplemented fuction. In children this function will copy data
				into appropriate formats for drawing with when vertices have changed.
			*/
			virtual void Refresh();

			/*! Sets the primitive type to be used while rendering.
			\param PrimitiveType The type that will be used for rendering 
			*/
			void SetPrimitiveType( Primitives PrimitiveType );

			/*! Gets a copy of a vertex
			\param Idx The index of the vertex
			\returns A copy of the vertex at any index 
			*/
			Vertex GetVertex( int Idx );

			/*! Gets a reference to a vertex for editing
			\param Idx The index of the vertex
			\return A reference to the vertex
			*/
			Vertex &EditVertex( int Idx );

			/*! Attempts to get any texture that's set to the object 
			*/
			void OnAttach();

			/*! Marks the Vertices object as dirty */
			void SetDirty();

			PROTECTED_FIELD( std::string, TextureName );
			PROTECTED_FIELD( Texture*, Texture );
		protected:

			/*! Pointer to an array of vertices */
			std::vector< Vertex > Vertices_;

			/*! Number of vertices that exist in the Vertices_ array */
			unsigned int VertexCount_;

			/*! The type of primitive that should be used when rendering */
			Primitives PrimitiveType_;

			/*! Marker to indicate if anything has been changed. Should never be false when drawing. */
			bool Dirty_;
		};
	}
}


#endif