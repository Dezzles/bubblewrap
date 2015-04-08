#include "Bubblewrap/Events/EventManager.hpp"
#include "Bubblewrap/Base/Entity.hpp"

namespace Bubblewrap
{
	namespace Events
	{
		EventManager::EventManager()
		{
			NextEventId_ = 0;
		}
		EventHandle EventManager::RegisterEvent( unsigned int EventType, std::function<void( Event* )> EventFunction )
		{
			EventStruct str( NextEventId_, EventFunction );
			EventsCallbacks_[ EventType ].push_back( str );

			unsigned int ret = NextEventId_;
			++NextEventId_;
			EventHandle retHandle;
			retHandle.Handle_ = ret;
			retHandle.Manager_ = this;
			return retHandle;
		}

		void EventManager::DeregisterEvent( unsigned int EventId )
		{
			for ( std::map<int, std::vector<EventStruct>>::iterator IterA = EventsCallbacks_.begin();
				  IterA != EventsCallbacks_.end(); ++IterA )
			{
				for ( std::vector<EventStruct>::iterator IterB = ( *IterA ).second.begin(); IterB != ( *IterA ).second.end(); )
				{
					if ( ( *IterB ).EventId_ == EventId )
					{
						IterB = ( *IterA ).second.erase( IterB );
					}
					else
					{
						++IterB;
					}

				}
			}
		}

		void EventManager::QueueEvent( Event Events )
		{
			EventQueue_.push_back( new Event( Events.EventType_, Events.Data_ ) );
		}

		void EventManager::ProcessEvents()
		{
			std::vector<Event*> ToHandleEvents = EventQueue_;
			unsigned int QueueSize = ToHandleEvents.size();
			EventQueue_.clear();

			for ( unsigned int Idx = 0; Idx < QueueSize; ++Idx )
			{
				for ( std::vector<EventStruct>::iterator IterB = EventsCallbacks_[ ToHandleEvents[ Idx ]->EventType_ ].begin(); 
					  IterB != EventsCallbacks_[ ToHandleEvents[ Idx ]->EventType_ ].end(); ++IterB )
				{
					( *IterB ).EventFunction_( ToHandleEvents[ Idx ] );
				}
				if ( ToHandleEvents[ Idx ]->Data_ != nullptr )
					delete ToHandleEvents[ Idx ]->Data_;
				delete ( ToHandleEvents[ Idx ] );
			}
		}
	}
}