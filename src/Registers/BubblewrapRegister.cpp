#include "Bubblewrap/Registers/BubblewrapRegister.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"

#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/Clock.hpp"
#include "Bubblewrap/Render/Sprite.hpp"
#include "Bubblewrap/Render/Texture.hpp"
#include "Bubblewrap/Render/Vertices.hpp"


namespace Bubblewrap
{
	namespace Registers
	{
		void BaseRegister::Register( void* ObjectRegister )
		{
			Base::ObjectRegister* Register = (Base::ObjectRegister*) ObjectRegister;
			Register->RegisterCreator( "Clock", &Base::Clock::Create, &Base::Clock::CreateJson, &Base::Clock::CopyDef );
			Register->RegisterCreator( "Entity", &Base::Entity::Create, &Base::Entity::CreateJson, &Base::Entity::CopyDef );
			Register->RegisterCreator( "Sprite", &Render::Sprite::Create, &Render::Sprite::CreateJson, &Render::Sprite::CopyDef );
			Register->RegisterCreator( "Texture", &Render::Texture::Create, &Render::Texture::CreateJson, &Render::Texture::CopyDef );
			Register->RegisterCreator( "Vertices", &Render::Vertices::Create, &Render::Vertices::CreateJson, &Render::Vertices::CopyDef );

		}
	}
}