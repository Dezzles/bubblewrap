#ifndef Types_HPP
#define Types_HPP

#include "Bubblewrap/Render/Colour.hpp"
#include "Bubblewrap/Math/Vector.hpp"
#include <string>
namespace Bubblewrap
{
	namespace Render
	{
		struct Vertex
		{
			Math::Vector2f Position_;
			Colour Colour_;
			Math::Vector2f TexCoords_;
		};

		enum class Primitives
		{
			Points,
			Lines,
			LinesStrip,
			Triangles,
			TrianglesStrip,
			TrianglesFan,
			Quads
		};






		class Converts
		{
		public:
			static Primitives PrimitiveFromString( std::string Name );
		};
	}
}

#endif