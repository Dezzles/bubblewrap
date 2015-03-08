#ifndef GoBase_H
#define GoBase_H

#include "EvtMessage.hpp"

namespace Bubblewrap
{
	namespace Base
	{
		class ObjectRegister;


		class GoBase
		{
			friend ObjectRegister;
		public:
			GoBase( );

			virtual void Update( float dt ) = 0;
			virtual void ReceiveMessage( EvtMessage Message );
			void Destroy();
			int Id();

			ObjectRegister & GetRegister();

			virtual void OnAttach();
			virtual void OnDetach();

		private:
			int Id_;
			bool Destroy_;
			ObjectRegister* ObjectRegister_;
		};
	}
}

#endif