#ifndef MGRCONTAINER_H
#define MGRCONTAINER_H

#include <algorithm>
#include <vector>
#include <functional>
namespace Bubblewrap
{
	namespace Managers
	{

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
		public:
			MgrContainer()
			{

			}

			T_* GetItem( unsigned int Idx )
			{
				assert( ( 0 <= Idx ) && ( Idx < Items_.size() ) );
				assert( Items_[ Idx ].Manager_ != nullptr );
				return Items_[ Idx ].Manager_;
			}

			T_* GetItem( std::string Name )
			{

				auto ret = std::find_if( Items_.begin(), Items_.end(),
							  [ = ]( MgrWrapper Item )
				{
					return Item.Valid_ && ( Item.Name_ == Name );
				} );
				assert( ret != Items_.end() );
				return ( *ret ).Manager_;
					
			}

			template<typename... Args >
			int Create(std::string Name, Args... args)
			{
				int ret = Items_.size();
				Items_.push_back( MgrWrapper( new T_( args... ), ret, Name ) );
				return ret;
			}

			void Destroy( unsigned int Idx )
			{
				assert( ( 0 <= Idx ) && ( Idx < Items_.size() ) );
				assert( Items_[ Idx ].Manager_ != nullptr );
				delete Items_[ Idx ].Manager_;

				Items_[ Idx ].Manager_ = nullptr;
				Items_[ Idx ].Valid_ = false;
			}

			void Update( float dt )
			{
				int count = Items_.size();
				for ( int Idx = 0; Idx < count; ++Idx )
				{
					Items_[ Idx ].Manager_->Update( dt );
				}
			}

			void OnAll( std::function<void(T_*)> fn )
			{
				for ( std::vector<MgrWrapper>::iterator iter = Items_.begin(); iter != Items_.end(); ++iter )
				{
					if ( ( *iter ).Valid_ )
						fn( ( *iter ).Manager_ );
				}
			}

		private:
			std::vector<MgrWrapper> Items_;
		};

	}
}




#endif