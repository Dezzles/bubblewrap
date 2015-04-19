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
#include "Bubblewrap/Render/Image.hpp"
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
			Register->RegisterCreator( "Entity", &Entity::Create, &Entity::CopyDef );

			Register->RegisterCreator( "Clock", &Disabled<Clock>::Create, &Disabled<Clock>::CopyDef );
			Register->RegisterCreator( "Sprite", &Sprite::Create, &Sprite::CopyDef );
			Register->RegisterCreator( "Texture", &Disabled<Texture>::Create, &Disabled<Texture>::CopyDef );
			Register->RegisterCreator( "Vertices", &Disabled<Vertices>::Create, &Disabled<Vertices>::CopyDef );
			Register->RegisterCreator( "Font", &Disabled<Font>::Create, &Disabled<Font>::CopyDef );
			Register->RegisterCreator( "Text", &Disabled<Text>::Create, &Disabled<Text>::CopyDef );
			Register->RegisterCreator( "Image", &Disabled<Image>::Create, &Disabled<Image>::CopyDef );

			Register->RegisterCreator( "StringList", &StringList::Create, &StringList::CopyDef );
			Register->RegisterCreator( "ResourceList", &ResourceList::Create, &ResourceList::CopyDef );

			Register->RegisterCreator( "Sound", &Disabled<Sound>::Create, &Disabled<Sound>::CopyDef );
			Register->RegisterCreator( "Music", &Disabled<Music>::Create, &Disabled<Music>::CopyDef );
			Register->RegisterCreator( "SoundBuffer", &Disabled<SoundBuffer>::Create,&Disabled<SoundBuffer>::CopyDef );

		}
	}
}