#include "Bubblewrap/Base/GoGame.hpp"
#include "Bubblewrap/Base/GoEntity.hpp"
#include "Bubblewrap/File/FiFSFile.hpp"
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

			File::FiFSFile file( Settings.BaseJson );
			file.Open(File::FsMode::Read);

			std::string fileData = file.ReadAll();
			file.Close();
			Json::Value root;
			Json::Reader rdr;

			rdr.parse( fileData, root );

			for ( unsigned int Idx = 0; Idx < root.size(); ++Idx )
			{
				Register_.CreateObject( root[ Idx ], nullptr );
			}
			sf::Clock clock;
			float PrevTime = clock.getElapsedTime().asSeconds();
			bool running = true;
			while ( running )
			{
				float CurrentTime = clock.getElapsedTime().asSeconds();
				float TimeStep = CurrentTime - PrevTime;

				Managers_.GetWindowManager().OnAll( [ TimeStep ]( Render::ReWindow* f )
				{
					f->Update( TimeStep );
					f->HandleEvents();
				} );
				Managers_.GetWindowManager().Update( TimeStep );
				
				Register_.Update( TimeStep );
				PrevTime = CurrentTime;



				Managers_.GetWindowManager().OnAll( [ TimeStep ]( Render::ReWindow* f )
				{
					f->Display();
				} );

			}
		}
	}
}
