#include "Bubblewrap/Base/GoBase.hpp"
#include "Bubblewrap/Base/DType.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		GoBase::GoBase( )
			: Destroy_( false )
		{

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

		void GoBase::ReceiveMessage( EvtMessage Message )
		{

		}
	}
}