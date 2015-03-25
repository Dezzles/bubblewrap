#include "Bubblewrap/Base/Game.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/File/FSFile.hpp"
#include "Bubblewrap/Logs/Log.hpp"
#include "Bubblewrap/Registers/BubblewrapRegister.hpp"
#include "Bubblewrap/Base/Clock.hpp"
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

			log.WriteLine( "Types: Registering" );
			Registers::BaseRegister::Register( &Register_ );
			for ( unsigned int Idx = 0; Idx < Settings.Registers_.size(); ++Idx )
			{
				Settings.Registers_[ Idx ]( &Register_ );
			}
			Settings.TypeRegistration_( &Register_ );

			for ( int Idx = 0; Idx < Settings.WindowCount_; ++Idx )
			{
				log.WriteLine( "Creating window" );
				Managers_.GetWindowManager().Create( Settings.WindowSettings_[ Idx ].Name_, &Settings.WindowSettings_[ Idx ] );
			}


			log.WriteLine( "Types: Registered" );
			log.WriteLine( "Resources: Loading" );
			for ( unsigned int Idx = 0; Idx < Settings.Resources_.size(); ++Idx )
			{
				Register_.LoadResources( Settings.Resources_[ Idx ] );
			}
			log.WriteLine( "Resources: Loaded" );
			log.WriteLine( "Packages: Loading" );
			for ( unsigned int Idx = 0; Idx < Settings.Packages_.size(); ++Idx )
			{
				Register_.LoadPackage( Settings.Packages_[ Idx ] );
			}
			log.WriteLine( "Packages: Loaded" );
			log.WriteLine( "Base object: Loading" );
			Register_.LoadObject( Settings.BaseObject_, nullptr );
			log.WriteLine( "Base object: Loaded" );
			Base::Clock* clock = (Base::Clock*)Register_.CreateObject(std::string("Clock"), nullptr);
			float PrevTime = clock->GetElapsedTime().AsSeconds();
			bool running = true;
			Register_.LogHierarchy();
			while ( running )
			{
				float CurrentTime = clock->GetElapsedTime().AsSeconds();
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
