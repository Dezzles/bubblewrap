#include "Bubblewrap/Events/EventHandle.hpp"
#include "Bubblewrap/Events/EventManager.hpp"

Bubblewrap::Events::EventHandle::EventHandle()
{
	UseCounter_ = new int();
	Manager_ = nullptr;
	*UseCounter_ = 0;
}

Bubblewrap::Events::EventHandle::EventHandle( const Bubblewrap::Events::EventHandle& Other )
{
	Destroy();
	UseCounter_ = Other.UseCounter_;
	Handle_ = Other.Handle_;
	Manager_ = Other.Manager_;
	++(*UseCounter_);
}

Bubblewrap::Events::EventHandle::~EventHandle()
{
	Destroy();
}

void Bubblewrap::Events::EventHandle::Destroy()
{
	if ( UseCounter_ == nullptr )
		return;
	--(*UseCounter_);
	if ( (*UseCounter_) <= 0 )
	{
		delete UseCounter_;
		UseCounter_ = nullptr;
		if ( Manager_ != nullptr )
		{
			Manager_->DeregisterEvent( Handle_ );
			Manager_ = nullptr;
		}
	}
}
