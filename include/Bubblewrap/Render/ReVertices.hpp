#ifndef REVERTICES_HPP
#define REVERTICES_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/ReDrawable.hpp"
#include "Bubblewrap/Render/ReTypes.hpp"
#include "Bubblewrap/Base/GoBase.hpp"
namespace Bubblewrap
{
	namespace Render
	{

		class ReVertices
			: public ReDrawable
		{
		public:
			ReVertices();
			~ReVertices();
			void Initialise( Json::Value Params );

			CREATE_REGISTER( ReVertices );

			virtual void Update( float dt );
			virtual void OnAttach();

			void AddVertex( ReVertex V );
			void Reserve( unsigned int Amount );
			void SetVertex( unsigned int Idx, ReVertex V );
			void Refresh();
			void SetPrimitiveType( RePrimitives PrimitiveType );
		protected:

			ReVertex* Vertices_;
			sf::Vertex* SFVertices_;

			unsigned int VertexCount_;
			unsigned int ReservedCount_;
			unsigned int SFReservedCount_;

			RePrimitives PrimitiveType_;

			bool Dirty_;
		};
	}
}


#endif