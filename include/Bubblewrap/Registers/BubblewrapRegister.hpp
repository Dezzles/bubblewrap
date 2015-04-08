#ifndef BUBBLEWRAPREGISTER_HPP
#define BUBBLEWRAPREGISTER_HPP

namespace Bubblewrap
{
	namespace Registers
	{
		/*! The registration class for the Base Bubblewrap engine.
			This is always called in Game
		*/
		class BaseRegister
		{
		public:
			/*! Registers all base Bubblewrap game objects
			\param ObjectRegister The object register held by game*/
			static void Register(void* ObjectRegister);
		};

	}

}

#endif