#ifndef MGRCONTAINER_H
#define MGRCONTAINER_H

#include <algorithm>
#include <vector>
#include <functional>
namespace Bubblewrap
{
	namespace Managers
	{
		class Managers;
		/*! A wrapper to automatically create a Manager list */
		template <class T_>
		class MgrContainer
		{
			struct MgrWrapper
			{
				MgrWrapper( T_* Mgr, int Index, std::string Name )
					: Manager_( Mgr ), Index_( Index ), Name_( Name )
				{
					Valid_ = ( Mgr != nullptr );
				}
				T_* Manager_;
				bool Valid_;
				int Index_;
				std::string Name_;
			};
			Managers* Owner_;
		public:
			/*! Creates a MgrContainer */
			MgrContainer()
			{

			}

			/*! Sets the current owner of this container*/
			void SetManager( Managers* Owner)
			{
				Owner_ = Owner;
			}

			/*! Gets an item from the container 
			\param Idx The index of the item to get
			\returns A pointer to the item requested.
			*/
			T_* GetItem( unsigned int Idx )
			{
				assert( ( 0 <= Idx ) && ( Idx < Items_.size() ) );
				assert( Items_[ Idx ].Manager_ != nullptr );
				return Items_[ Idx ].Manager_;
			}

			/*! Gets an item from the container by name.
			\param Name The name of the item we're searching for.
			\returns A pointer to the item found, or nullptr if no matching item could be found.
			*/
			T_* GetItem( std::string Name )
			{

				auto ret = std::find_if( Items_.begin(), Items_.end(),
							  [ = ]( MgrWrapper Item )
				{
					return Item.Valid_ && ( Item.Name_ == Name );
				} );
				/*assert( ret != Items_.end() );/**/
				return ( *ret ).Manager_;
					
			}

			/*! Creates a new instance of the BaseManager that this object wraps.
			\param Name The name that should be assigned to this object
			\param Params A pointer to the object containing the details required to create the new object
			\returns The index of the newly created item.
			*/
			int Create(std::string Name, void* Params )
			{
				int ret = Items_.size();
				Items_.push_back( MgrWrapper( Creator_(Params) , ret, Name ) );
				Items_[ ret ].Manager_->SetManager( Owner_ );
				return ret;
			}

			/*! Destroys an item stored in the container.
			\param Idx The index of the item to be destroyed.
			*/
			void Destroy( unsigned int Idx )
			{
				assert( ( 0 <= Idx ) && ( Idx < Items_.size() ) );
				assert( Items_[ Idx ].Manager_ != nullptr );
				delete Items_[ Idx ].Manager_;

				Items_[ Idx ].Manager_ = nullptr;
				Items_[ Idx ].Valid_ = false;
			}

			/*! Updates all of the items currently stored in the container.
			\param dt The timestep, in seconds, since the last update.
			*/
			void Update( float dt )
			{
				int count = Items_.size();
				for ( int Idx = 0; Idx < count; ++Idx )
				{
					if ( Items_[ Idx ].Valid_ )
						Items_[ Idx ].Manager_->Update( dt );
				}
			}

			/*! Runs a given function on all items stored
			\param fn The function to run on all of the items stored in the container. 
			*/
			void OnAll( std::function<void(T_*)> fn )
			{
				for ( std::vector<MgrWrapper>::iterator iter = Items_.begin(); iter != Items_.end(); ++iter )
				{
					if ( ( *iter ).Valid_ )
						fn( ( *iter ).Manager_ );
				}
			}

			/*! Sets the create function for items stored in the container.
			\param Fn A function that returns a new instance of an item.
			*/
			void SetCreate( std::function<T_* ( void* )> Fn )
			{
				Creator_ = Fn;
			}

		private:
			std::vector<MgrWrapper> Items_;

			std::function<T_*( void* )> Creator_;
		};

	}
}




#endif