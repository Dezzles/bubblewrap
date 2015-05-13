#include "Bubblewrap/Render/Shader.hpp"
#include "Bubblewrap/Base/Component.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		Shader::Shader()
		{

		}

		void Shader::Initialise( Json::Value Params )
		{
			Resource::Initialise( Params );
			
		}

		void Shader::Copy( Shader* Target, Shader* Base )
		{
			Resource::Copy( Target, Base );
		}

	}
}