#include "Bubblewrap/Base/Game.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/File/FSFile.hpp"
namespace Bubblewrap
{
	namespace Game
	{
		GoGame::GoGame()
		{
			Register_.SetManager( &Managers_ );
		}

		void GoGame::Run( GoGameSettings Settings )
		{
			for ( int Idx = 0; Idx < Settings.WindowCount_; ++Idx )
			{
				Managers_.GetWindowManager().Create( Settings.WindowSettings_[ Idx ].Name_, Settings.WindowSettings_[ Idx ] );
			}

			Settings.TypeRegistration_( &Register_ );

			for ( unsigned int Idx = 0; Idx < Settings.Packages_.size(); ++Idx )
			{
				Register_.LoadPackage( Settings.Packages_[ Idx ] );
			}

			Register_.LoadObject( Settings.BaseObject_, nullptr );
			sf::Clock clock;
			float PrevTime = clock.getElapsedTime().asSeconds();
			bool running = true;
			while ( running )
			{
				float CurrentTime = clock.getElapsedTime().asSeconds();
				float TimeStep = CurrentTime - PrevTime;

				Managers_.GetWindowManager().OnAll( [ TimeStep ]( Render::Window* f )
				{
					f->Update( TimeStep );
					f->HandleEvents();
				} );
				Managers_.GetWindowManager().Update( TimeStep );
				
				Register_.Update( TimeStep );
				PrevTime = CurrentTime;



				Managers_.GetWindowManager().OnAll( [ TimeStep ]( Render::Window* f )
				{
					f->Display();
				} );

			}
		}
	}
}
