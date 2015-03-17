#include "Bubblewrap/Base/Game.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/File/FSFile.hpp"
#include "Bubblewrap/Logs/Log.hpp"

namespace Bubblewrap
{
	namespace Game
	{
		Game::Game()
		{
			Register_.SetManager( &Managers_ );
		}

		void Game::Run( GoGameSettings Settings )
		{
			Logs::Log log("Game::Run");
			log.WriteLine( "Starting game" );
			for ( int Idx = 0; Idx < Settings.WindowCount_; ++Idx )
			{
				log.WriteLine( "Creating window" );
				Managers_.GetWindowManager().Create( Settings.WindowSettings_[ Idx ].Name_, Settings.WindowSettings_[ Idx ] );
			}

			log.WriteLine( "Types: Registering" );
			Register_.RegisterClasses();
			Settings.TypeRegistration_( &Register_ );
			log.WriteLine( "Types: Registered" );
			for ( unsigned int Idx = 0; Idx < Settings.Packages_.size(); ++Idx )
			{
				log.WriteLine( "Packages: Loading" );
				Register_.LoadPackage( Settings.Packages_[ Idx ] );
				log.WriteLine( "Packages: Loaded" );
			}
			log.WriteLine( "Base object: Loading" );
			Register_.LoadObject( Settings.BaseObject_, nullptr );
			log.WriteLine( "Base object: Loaded" );
			sf::Clock clock;
			float PrevTime = clock.getElapsedTime().asSeconds();
			bool running = true;
			// Register_.LogHierarchy();
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

				Managers_.GetEventManager().ProcessMessages();
			}
		}
	}
}
