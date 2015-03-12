#include "Bubblewrap/Render/ReVertices.hpp"
#include "Bubblewrap/Base/GoBase.hpp"
#include "Bubblewrap/Render/ReTypes.hpp"
#include "Bubblewrap/Math/MaVector.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		ReVertices::ReVertices()
		{
			VertexCount_ = 0;
			ReservedCount_ = 0;
			SFReservedCount_ = 0;

			Vertices_ = new ReVertex[ 0 ];
			SFVertices_ = new sf::Vertex[ 0 ];
			Dirty_ = false;
		}


		ReVertices::~ReVertices()
		{
			delete Vertices_;
			delete SFVertices_;
		}

		void ReVertices::Initialise( Json::Value Params )
		{
			ReDrawable::Initialise( Params );

			SetPrimitiveType( ReConverts::RePrimitiveFromString( Params[ "primitivetype" ].asString() ) );
			Reserve( Params[ "vertices" ].size() );
			int uCount = Params[ "vertices" ].size();
			VertexCount_ = uCount;
			for ( int Idx = 0; Idx < uCount; ++Idx )
			{
				Vertices_[ Idx ].Colour_ = ReColour( Params[ "vertices" ][ Idx ][ "colour" ].asString() );
				Vertices_[ Idx ].Position_ = Math::Vector2f( Params[ "vertices" ][ Idx ][ "position" ].asString() );
				Vertices_[ Idx ].Colour_ = ReColour( Params[ "vertices" ][ Idx ][ "colour" ].asString() );
			}
		}


		void ReVertices::Copy( ReVertices* Target, ReVertices* Base )
		{
			ReDrawable::Copy( Target, Base );
			Target->Reserve( Base->VertexCount_ );
			memcpy( Target->Vertices_, Base->Vertices_, Base->VertexCount_ * sizeof( ReVertex ) );

			Target->PrimitiveType_ = Base->PrimitiveType_;
			Target->ReservedCount_ = Base->VertexCount_;
			Target->VertexCount_ = Base->VertexCount_;
			Target->Refresh();
		}

		void ReVertices::OnAttach()
		{

		}

		void ReVertices::Update( float dt )
		{
			assert( !Dirty_ );
			if ( ( Window_ == nullptr ) && ( WindowName_ != "" ) )
			{
				Window_ = GetManager().GetWindowManager().GetItem( WindowName_ );
			}
			if ( Window_ == nullptr )
				return;

			sf::RenderWindow* rw = Window_->GetWindow<sf::RenderWindow>();
			sf::PrimitiveType PrimitiveType;
			switch ( PrimitiveType_ )
			{
			case RePrimitives::Lines:
				PrimitiveType = sf::PrimitiveType::Lines;
				break;
			case RePrimitives::LinesStrip:
				PrimitiveType = sf::PrimitiveType::LinesStrip;
				break;
			case RePrimitives::Points:
				PrimitiveType = sf::PrimitiveType::Points;
				break;
			case RePrimitives::Quads:
				PrimitiveType = sf::PrimitiveType::Quads;
				break;
			case RePrimitives::Triangles:
				PrimitiveType = sf::PrimitiveType::Triangles;
				break;
			case RePrimitives::TrianglesStrip:
				PrimitiveType = sf::PrimitiveType::TrianglesStrip;
				break;
			case RePrimitives::TrianglesFan:
				PrimitiveType = sf::PrimitiveType::TrianglesFan;
				break;
			}
			rw->draw( SFVertices_, VertexCount_, PrimitiveType );
		}

		void ReVertices::SetPrimitiveType( RePrimitives PrimitiveType )
		{
			PrimitiveType_ = PrimitiveType;
		}

		void ReVertices::AddVertex( ReVertex V )
		{
			if ( VertexCount_ == ReservedCount_ )
			{
				Reserve( 1 );
			}
			Vertices_[ VertexCount_ ] = V;
			++VertexCount_;
			Dirty_ = true;
		}
		void ReVertices::Reserve( unsigned int Amount )
		{
			int CurrentCount = ReservedCount_;
			int NewCount = ReservedCount_ + Amount;
			ReVertex* newMem = new ReVertex[ NewCount ];
			memset( newMem, 0, NewCount * sizeof( ReVertex ) );
			memcpy( newMem, Vertices_, CurrentCount * sizeof( ReVertex ) );
			delete Vertices_;
			Vertices_ = newMem;
			ReservedCount_ = NewCount;
		}
		void ReVertices::SetVertex( unsigned int Idx, ReVertex V )
		{
			assert( Idx < VertexCount_ );
			Vertices_[ Idx ] = V;
			Dirty_ = true;
		}

		void ReVertices::Refresh()
		{
			if ( SFReservedCount_ < VertexCount_ )
			{
				delete SFVertices_;
				SFVertices_ = new sf::Vertex[ VertexCount_ ];
				SFReservedCount_ = VertexCount_;
			}
			for ( unsigned int Idx = 0; Idx < VertexCount_; ++Idx )
			{
				SFVertices_[ Idx ].color = sf::Color( Vertices_[ Idx ].Colour_.R(), Vertices_[ Idx ].Colour_.G(), Vertices_[ Idx ].Colour_.B(), Vertices_[ Idx ].Colour_.A() );
				SFVertices_[ Idx ].position = sf::Vector2f( Vertices_[ Idx ].Position_.X(), Vertices_[ Idx ].Position_.Y() );
				SFVertices_[ Idx ].texCoords = sf::Vector2f( Vertices_[ Idx ].TexCoords_.X(), Vertices_[ Idx ].TexCoords_.Y() );
			}
			Dirty_ = false;
		}
	}
}