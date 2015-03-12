#include "Bubblewrap/Render/Drawable.hpp"
#include "Bubblewrap/Base/Base.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		Drawable::Drawable()
		{
			WindowName_ = "";
			Window_ = nullptr;
		}

		void Drawable::Initialise( Json::Value Params )
		{
			GoBase::Initialise( Params );
			SetWindow( Params[ "window" ].asString() );
		}


		void Drawable::Copy( Drawable* Target, Drawable* Base )
		{
			Target->SetWindow( Base->Window_ );
			Target->WindowName_ = Base->WindowName_;
		}

		void Drawable::OnAttach()
		{

		}

		void Drawable::SetWindow( std::string Name )
		{
			WindowName_ = Name;
			Window_ = GetManager().GetWindowManager().GetItem( Name );
		}

		void Drawable::SetWindow( Window* Window )
		{
			Window_ = Window;
		}

		void Drawable::Update( float dt )
		{
			if ( ( Window_ == nullptr ) && ( WindowName_ != "" ) )
			{
				Window_ = GetManager().GetWindowManager().GetItem( WindowName_ );
			}
		}

	}
}