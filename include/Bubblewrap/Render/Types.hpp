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
		struct Vertex
		{
			Math::Vector3f Position_;
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