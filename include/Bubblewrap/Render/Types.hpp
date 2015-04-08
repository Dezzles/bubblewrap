#ifndef Types_HPP
#define Types_HPP

#include "Bubblewrap/Render/Colour.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Math/Vector3.hpp"
#include <string>
namespace Bubblewrap
{
	namespace Render
	{
		/*! Contains the data required to draw vertices
		*/
		struct Vertex
		{
			/*! The position of the vertex */
			Math::Vector3f Position_;
			/*! The colour of the vertex */
			Colour Colour_;
			/*! The UV or texture coordinates of the vertex */
			Math::Vector2f TexCoords_;
		};

		/*! The primitive types used when rendering vertices */
		enum class Primitives
		{
			/*! Collection of points */
			Points,
			/*! Line pairs */
			Lines,
			/*! A continues set of lines */
			LinesStrip,
			/*! Individual triangles in sets of three*/
			Triangles,
			/*! A triangle strip */
			TrianglesStrip,
			/*! A triangle fan*/
			TrianglesFan,
			/*! Individual quads*/
			Quads
		};





		/*! Contains functions used for converting types */
		class Converts
		{
		public:
			/*! Converts a string to a primivite type
			\param Name The name of the primitive
			\returns The associated primitive, if no match is found, Primitives::Points is returned.
			*/
			static Primitives PrimitiveFromString( std::string Name );
		};
	}
}

#endif