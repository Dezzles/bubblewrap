#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/DType.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		GoBase::GoBase( )
			: Destroy_( false )
		{

		}

		void GoBase::Copy( GoBase* Target, GoBase* Base )
		{
			Target->Name_ = Base->Name_;
		}

		int GoBase::Id()
		{
			return Id_;
		}

		void GoBase::Destroy()
		{
			Destroy_ = true;
		}

		ObjectRegister & GoBase::GetRegister()
		{
			return *ObjectRegister_;
		}

		void GoBase::OnAttach()
		{

		}

		void GoBase::OnDetach()
		{

		}

		/*void GoBase::ReceiveMessage( EvtMessage Message )
		{

		}/**/

		void GoBase::Initialise( Json::Value Params )
		{
			if ( !Params[ "name" ].isNull() )
				Name_ = Params[ "name" ].asString();
		}

		Entity* GoBase::GetParentEntity()
		{	
			return Parent_;
		}

		Managers::Managers& GoBase::GetManager()
		{
			return *Manager_;
		}

		std::string GoBase::GetName()
		{
			return Name_;
		}
	}
}