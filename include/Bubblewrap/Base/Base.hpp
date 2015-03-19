#ifndef GoBase_H
#define GoBase_H

#include "Json/Json.h"
namespace Bubblewrap
{
	namespace Managers
	{
		class Managers;
	}
	namespace Base
	{
		class ObjectRegister;
		class Entity;

		class GoBase
		{
			friend ObjectRegister;
		public:
			GoBase( );
			static void Copy( GoBase* Target, GoBase* Base );
			virtual void Update( float dt ) = 0;
			void Destroy();
			int Id();

			ObjectRegister & GetRegister();

			Managers::Managers& GetManager();
			virtual void OnAttach();
			virtual void OnDetach();

			virtual void Initialise( Json::Value Params );

			Entity* GetParentEntity();
			std::string GetName();

			virtual std::string TypeName() = 0;
		private:

			Entity* Parent_;
			int Id_;
			bool Destroy_;
			ObjectRegister* ObjectRegister_;
			GoBase* Basis_;

			Managers::Managers* Manager_;

			std::string Name_;
		};
	}
}

#endif