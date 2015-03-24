#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Render/Vertices.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Render/Types.hpp"
#include "Bubblewrap/Math/Vector2.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		Vertices::Vertices()
		{
			VertexCount_ = 0;
			ReservedCount_ = 0;

			Vertices_ = new Vertex[ 0 ];
			Dirty_ = false;
		}


		Vertices::~Vertices()
		{
			delete Vertices_;
		}

		void Vertices::Initialise( Json::Value Params )
		{
			Drawable::Initialise( Params );

			SetPrimitiveType( Converts::PrimitiveFromString( Params[ "primitiveType" ].asString() ) );
			Reserve( Params[ "vertices" ].size() );
			int uCount = Params[ "vertices" ].size();
			VertexCount_ = uCount;
			for ( int Idx = 0; Idx < uCount; ++Idx )
			{
				Vertices_[ Idx ].Colour_ = Colour( Params[ "vertices" ][ Idx ][ "colour" ].asString() );
				Vertices_[ Idx ].Position_ = Math::Vector3f( Params[ "vertices" ][ Idx ][ "position" ].asString() );
				Vertices_[ Idx ].TexCoords_ = Math::Vector2f( Params[ "vertices" ][ Idx ][ "textCoords" ].asString() );
			}
		}


		void Vertices::Copy( Vertices* Target, Vertices* Base )
		{
			Drawable::Copy( Target, Base ); 
			Target->Reserve( Base->VertexCount_ );
			memcpy( Target->Vertices_, Base->Vertices_, Base->VertexCount_ * sizeof( Vertex ) );

			Target->PrimitiveType_ = Base->PrimitiveType_;
			Target->ReservedCount_ = Base->VertexCount_;
			Target->VertexCount_ = Base->VertexCount_;
			Target->Refresh();
		}

		void Vertices::OnAttach()
		{

		}

		void Vertices::Update( float dt )
		{
			Drawable::Update( dt );
			assert( !Dirty_ );
			if ( ( Window_ == nullptr ) && ( WindowName_ != "" ) )
			{
				Window_ = GetManager().GetWindowManager().GetItem( WindowName_ );
			}
			if ( Window_ == nullptr )
				return;


		}

		void Vertices::SetPrimitiveType( Primitives PrimitiveType )
		{
			PrimitiveType_ = PrimitiveType;
		}

		void Vertices::AddVertex( Vertex V )
		{
			if ( VertexCount_ == ReservedCount_ )
			{
				Reserve( 1 );
			}
			Vertices_[ VertexCount_ ] = V;
			++VertexCount_;
			Dirty_ = true;
		}
		void Vertices::Reserve( unsigned int Amount )
		{
			int CurrentCount = ReservedCount_;
			int NewCount = ReservedCount_ + Amount;
			Vertex* newMem = new Vertex[ NewCount ];
			memset( newMem, 0, NewCount * sizeof( Vertex ) );
			memcpy( newMem, Vertices_, CurrentCount * sizeof( Vertex ) );
			delete Vertices_;
			Vertices_ = newMem;
			ReservedCount_ = NewCount;
		}
		void Vertices::SetVertex( unsigned int Idx, Vertex V )
		{
			assert( Idx < VertexCount_ );
			Vertices_[ Idx ] = V;
			Dirty_ = true;
		}

		void Vertices::Refresh()
		{

		}
		Vertex Vertices::GetVertex( int Idx )
		{
			return Vertices_[ Idx ];
		}

		Vertex &Vertices::EditVertex( int Idx )
		{
			Dirty_ = true;
			return Vertices_[ Idx ];
		}
	}
}