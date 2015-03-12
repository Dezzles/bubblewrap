#include "Bubblewrap/Render/ReTypes.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		RePrimitives ReConverts::RePrimitiveFromString( std::string Name )
		{
			if ( Name == "Points" )
				return RePrimitives::Points;
			else if ( Name == "Lines" )
				return RePrimitives::Lines;
			else if ( Name == "LinesStrip" )
				return RePrimitives::LinesStrip;
			else if ( Name == "Triangles" )
				return RePrimitives::Triangles;
			else if ( Name == "TrianglesStrip" )
				return RePrimitives::TrianglesStrip;
			else if ( Name == "TrianglesFan" )
				return RePrimitives::TrianglesFan;
			else if ( Name == "LinesStrip" )
				return RePrimitives::Quads;
			
			throw "Invalid primitive set";
			return RePrimitives::Points;
		}

	}
}