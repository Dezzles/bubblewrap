#include "Bubblewrap/Registers/BubblewrapRegister.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"

#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/Clock.hpp"
#include "Bubblewrap/Render/Sprite.hpp"
#include "Bubblewrap/Render/Texture.hpp"
#include "Bubblewrap/Render/Vertices.hpp"
#include "Bubblewrap/Render/Font.hpp"
#include "Bubblewrap/Render/Text.hpp"
#include "Bubblewrap/Base/Disabled.hpp"
#include "Bubblewrap/Data/StringList.hpp"
#include "Bubblewrap/Data/ResourceList.hpp"

#include "Bubblewrap/Audio/Music.hpp"
#include "Bubblewrap/Audio/Sound.hpp"
#include "Bubblewrap/Audio/SoundBuffer.hpp"
namespace Bubblewrap
{
	namespace Registers
	{
		using namespace Base;
		using namespace Render;
		using namespace Data;
		using namespace Audio;
		void BaseRegister::Register( void* ObjRegister )
		{
			ObjectRegister* Register = ( ObjectRegister* ) ObjRegister;
			Register->RegisterCreator( "Entity", &Entity::Create, &Entity::CreateJson, &Entity::CopyDef );

			Register->RegisterCreator( "Clock", &Disabled<Clock>::Create, &Disabled<Clock>::CreateJson, &Disabled<Clock>::CopyDef );
			Register->RegisterCreator( "Sprite", &Disabled<Sprite>::Create, &Disabled<Sprite>::CreateJson, &Disabled<Sprite>::CopyDef );
			Register->RegisterCreator( "Texture", &Disabled<Texture>::Create, &Disabled<Texture>::CreateJson, &Disabled<Texture>::CopyDef );
			Register->RegisterCreator( "Vertices", &Disabled<Vertices>::Create, &Disabled<Vertices>::CreateJson, &Disabled<Vertices>::CopyDef );
			Register->RegisterCreator( "Font", &Disabled<Font>::Create, &Disabled<Font>::CreateJson, &Disabled<Font>::CopyDef );
			Register->RegisterCreator( "Text", &Disabled<Text>::Create, &Disabled<Text>::CreateJson, &Disabled<Text>::CopyDef );

			Register->RegisterCreator( "StringList", &StringList::Create, &StringList::CreateJson, &StringList::CopyDef );
			Register->RegisterCreator( "ResourceList", &ResourceList::Create, &ResourceList::CreateJson, &ResourceList::CopyDef );

			Register->RegisterCreator( "Sound", &Disabled<Sound>::Create, &Disabled<Sound>::CreateJson, &Disabled<Sound>::CopyDef );
			Register->RegisterCreator( "Music", &Disabled<Music>::Create, &Disabled<Music>::CreateJson, &Disabled<Music>::CopyDef );
			Register->RegisterCreator( "SoundBuffer", &Disabled<SoundBuffer>::Create, &Disabled<SoundBuffer>::CreateJson, &Disabled<SoundBuffer>::CopyDef );

		}
	}
}