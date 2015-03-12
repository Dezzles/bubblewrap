#ifndef RETYPES_HPP
#define RETYPES_HPP

#include "Bubblewrap/Render/ReColour.hpp"
#include "Bubblewrap/Math/MaVector.hpp"
#include <string>
namespace Bubblewrap
{
	namespace Render
	{
		struct ReVertex
		{
			Math::Vector2f Position_;
			ReColour Colour_;
			Math::Vector2f TexCoords_;
		};

		enum class RePrimitives
		{
			Points,
			Lines,
			LinesStrip,
			Triangles,
			TrianglesStrip,
			TrianglesFan,
			Quads
		};






		class ReConverts
		{
		public:
			static RePrimitives RePrimitiveFromString( std::string Name );
		};
	}
}

#endif