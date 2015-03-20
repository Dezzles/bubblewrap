#ifndef Vertices_HPP
#define Vertices_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/Drawable.hpp"
#include "Bubblewrap/Render/Types.hpp"
#include "Bubblewrap/Base/Base.hpp"
namespace Bubblewrap
{
	namespace Render
	{

		class Vertices
			: public Drawable
		{
		public:
			Vertices();
			~Vertices();
			void Initialise( Json::Value Params );

			CREATE_REGISTER( Vertices );

			virtual void Update( float dt );
			virtual void OnAttach();

			void AddVertex( Vertex V );
			void Reserve( unsigned int Amount );
			void SetVertex( unsigned int Idx, Vertex V );
			void Refresh();
			void SetPrimitiveType( Primitives PrimitiveType );
		protected:

			Vertex* Vertices_;

			unsigned int VertexCount_;
			unsigned int ReservedCount_;

			Primitives PrimitiveType_;

			bool Dirty_;
		};
	}
}


#endif