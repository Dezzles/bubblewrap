#include "Bubblewrap/Render/ReDrawable.hpp"
#include "Bubblewrap/Base/GoBase.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		ReDrawable::ReDrawable()
		{
			WindowName_ = "";
			Window_ = nullptr;
		}

		void ReDrawable::Initialise( Json::Value Params )
		{
			GoBase::Initialise( Params );
			SetWindow( Params[ "window" ].asString() );
		}


		void ReDrawable::Copy( ReDrawable* Target, ReDrawable* Base )
		{
			Target->SetWindow( Base->Window_ );
			Target->WindowName_ = Base->WindowName_;
		}

		void ReDrawable::OnAttach()
		{

		}

		void ReDrawable::SetWindow( std::string Name )
		{
			WindowName_ = Name;
			Window_ = GetManager().GetWindowManager().GetItem( Name );
		}

		void ReDrawable::SetWindow( ReWindow* Window )
		{
			Window_ = Window;
		}

		void ReDrawable::Update( float dt )
		{
			if ( ( Window_ == nullptr ) && ( WindowName_ != "" ) )
			{
				Window_ = GetManager().GetWindowManager().GetItem( WindowName_ );
			}
		}

	}
}