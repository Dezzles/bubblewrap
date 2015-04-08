#include "Bubblewrap/Render/Font.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		Font::Font()
		{
		}

		void Font::Initialise( Json::Value Params )
		{
			Base::Resource::Initialise( Params );
		}


		void Font::Copy( Font* Target, Font* Base )
		{
			Base::Resource::Copy( Target, Base );
		}

	}
}