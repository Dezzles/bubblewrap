#include "Bubblewrap/Base/Game.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/File/File.hpp"
#include "Bubblewrap/Logs/Log.hpp"
#include "Bubblewrap/Registers/BubblewrapRegister.hpp"
#include "Bubblewrap/Base/Clock.hpp"
#include <time.h>
namespace Bubblewrap
{
	namespace Game
	{
		Game::Game()
		{
			Register_.SetManager( &Managers_ );
			srand((unsigned int)time(0));
			KeepRunning_ = true;
		}

		void Game::Run( GameSettings Settings )
		{
			Logs::Log log("Game::Run");
			log.WriteLine( "Starting game", Logs::StaticLog::VERBOSE );


			log.WriteLine( "Types: Registering", Logs::StaticLog::VERBOSE );
			Registers::BaseRegister::Register( &Register_ );
			for ( unsigned int Idx = 0; Idx < Settings.Registers_.size(); ++Idx )
			{
				Settings.Registers_[ Idx ]( &Register_ );
			}
			Settings.TypeRegistration_( &Register_ );

			for ( int Idx = 0; Idx < Settings.WindowCount_; ++Idx )
			{
				log.WriteLine( "Creating window", Logs::StaticLog::VERBOSE );
				Managers_.GetWindowManager().Create( Settings.WindowSettings_[ Idx ].Name_, &Settings.WindowSettings_[ Idx ] );
			}

			Managers_.GetFileManager().Initialise();
			/* TODO Improve this */
			for ( unsigned int Idx = 0; Idx < Settings.Paths_.size(); ++Idx )
			{
				Managers_.GetFileManager().AddPath( Settings.Paths_[ 0 ], false );
			}
			log.WriteLine( "Types: Registered", Logs::StaticLog::VERBOSE );
			log.WriteLine( "Resources: Loading", Logs::StaticLog::VERBOSE );
			for ( unsigned int Idx = 0; Idx < Settings.Resources_.size(); ++Idx )
			{
				Register_.LoadResources( Settings.Resources_[ Idx ] );
			}
			log.WriteLine( "Resources: Loaded", Logs::StaticLog::VERBOSE );
			log.WriteLine( "Packages: Loading", Logs::StaticLog::VERBOSE );
			for ( unsigned int Idx = 0; Idx < Settings.Packages_.size(); ++Idx )
			{
				Register_.LoadPackage( Settings.Packages_[ Idx ] );
			}
			log.WriteLine( "Packages: Loaded", Logs::StaticLog::VERBOSE );
			log.WriteLine( "Base object: Loading", Logs::StaticLog::VERBOSE );
			Register_.LoadObject( Settings.BaseObject_, nullptr );
			log.WriteLine( "Base object: Loaded", Logs::StaticLog::VERBOSE );
			Base::Clock* clock = (Base::Clock*)Register_.CreateObject(std::string("Clock"), nullptr);
			float PrevTime = clock->GetElapsedTime().AsSeconds();
			Register_.LogHierarchy();
			Managers_.SetGame( this );
			while ( KeepRunning_ )
			{
				float CurrentTime = clock->GetElapsedTime().AsSeconds();
				float TimeStep = CurrentTime - PrevTime;


				Managers_.GetWindowManager().OnAll( [ TimeStep ]( Render::Window* f )
				{
					f->Update( TimeStep );
					f->HandleEvents();
				} );
				Managers_.GetWindowManager().Update( TimeStep );
				
				Register_.AttachItems();
				Register_.Update( TimeStep );
				PrevTime = CurrentTime;


				Managers_.GetWindowManager().OnAll( [ TimeStep ]( Render::Window* f )
				{
					f->Display();
				} );

				Managers_.GetEventManager().ProcessEvents();

				Register_.DestroyPhase();
			}
		}

		void Game::Shutdown()
		{
			KeepRunning_ = false;
		}
	}
}
