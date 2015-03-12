#include "Bubblewrap/Render/Types.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		Primitives Converts::PrimitiveFromString( std::string Name )
		{
			if ( Name == "Points" )
				return Primitives::Points;
			else if ( Name == "Lines" )
				return Primitives::Lines;
			else if ( Name == "LinesStrip" )
				return Primitives::LinesStrip;
			else if ( Name == "Triangles" )
				return Primitives::Triangles;
			else if ( Name == "TrianglesStrip" )
				return Primitives::TrianglesStrip;
			else if ( Name == "TrianglesFan" )
				return Primitives::TrianglesFan;
			else if ( Name == "LinesStrip" )
				return Primitives::Quads;
			
			throw "Invalid primitive set";
			return Primitives::Points;
		}

	}
}