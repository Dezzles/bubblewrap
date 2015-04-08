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
			Visible_ = true;
		}

		void Drawable::Initialise( Json::Value Params )
		{
			GoBase::Initialise( Params );
			SetWindow( Params[ "window" ].asString() );
			DrawOrder_ = Params[ "drawOrder" ].asInt();
		}


		void Drawable::Copy( Drawable* Target, Drawable* Base )
		{
			Target->SetWindow( Base->Window_ );
			Target->WindowName_ = Base->WindowName_;
			Target->DrawOrder_ = Base->DrawOrder_;
			Target->Visible_ = Base->Visible_;
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
			if ( Visible_ )
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

		bool Drawable::GetVisible()
		{
			return Visible_;
		}

		void Drawable::SetVisible( bool Visible )
		{
			Visible_ = Visible;
		}

	}
}