#include "Bubblewrap/Render/Drawable.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
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
			DrawOrder_ = Params[ "draworder" ].asInt();
		}


		void Drawable::Copy( Drawable* Target, Drawable* Base )
		{
			Target->SetWindow( Base->Window_ );
			Target->WindowName_ = Base->WindowName_;
			Target->DrawOrder_ = Base->DrawOrder_;
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
			Window_->AddToQueue(this);
		}

		int Drawable::GetDrawOrder()
		{
			return DrawOrder_;
		}

		void Drawable::SetDrawOrder( int DrawOrder )
		{
			DrawOrder_ = DrawOrder;
		}

		void Drawable::Draw()
		{

		}

	}
}