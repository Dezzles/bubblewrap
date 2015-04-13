#ifndef DEFINES_H
#define DEFINES_H

#include "DType.hpp"
#include "Bubblewrap/Logs/StaticLog.hpp"
#include "json/json.h"
#include "Bubblewrap/Base/Assert.hpp"

#define CREATE_REGISTER(TYPE)  	\
	/*! Creates a disabled instance of TYPE. \return A pointer to a new instance of NAME.*/\
	static Bubblewrap::Base::GoBase* Create( ) \
		{ \
	return static_cast<Bubblewrap::Base::GoBase*> ( new TYPE( ) ); \
		} \
	/*! Copies an instance of TYPE \param Target The object data will be copied to. \param Base The object data will be copied from */\
	static void Copy( TYPE* Target, TYPE* Base ); \
	/*! Copies an instance of TYPE \param Target The object data will be copied to. \param Base The object data will be copied from */\
	static void CopyDef( Bubblewrap::Base::GoBase* Target, Bubblewrap::Base::GoBase* Base ) \
		{\
		TYPE* target = dynamic_cast<TYPE*>( Target ); \
		TYPE* base = dynamic_cast<TYPE*>( Base ); \
	Copy( target, base ); \
		} \
	/*! Returns the type name of the object. \returns Returns "NAME".*/\
	virtual std::string TypeName() \
		{\
		return #TYPE;\
		}

#define CREATE_REGISTER_OVERRIDE(TYPE, FAKENAME)  	\
	/*! Creates a disabled instance of TYPE. \return A pointer to a new instance of NAME.*/\
		static Bubblewrap::Base::GoBase* Create( ) \
		{ \
			return static_cast<Bubblewrap::Base::GoBase*> ( new TYPE( ) ); \
		} \
	/*! Copies an instance of TYPE \param Target The object data will be copied to. \param Base The object data will be copied from */\
		static void Copy( TYPE* Target, TYPE* Base ); \
	/*! Copies an instance of TYPE \param Target The object data will be copied to. \param Base The object data will be copied from */\
		static void CopyDef( Bubblewrap::Base::GoBase* Target, Bubblewrap::Base::GoBase* Base ) \
		{\
			TYPE* target = dynamic_cast<TYPE*>( Target ); \
			TYPE* base = dynamic_cast<TYPE*>( Base ); \
			Copy( target, base ); \
		} \
	/*! Returns the type name of the object. \returns Returns "NAME".*/\
		virtual std::string TypeName() \
		{\
			return #FAKENAME;\
		}

#define CREATE_REGISTER_DISABLED(TYPE, TYPENAME)  	\
	/*! Creates a disabled instance of TYPE. \return A pointer to a new instance of NAME.*/\
		static Bubblewrap::Base::GoBase* Create( ) \
				{ \
				HardTest( false, "Creating unimplemented class: "+ std::string( typeid( TYPE ).name() )); \
				return static_cast<Bubblewrap::Base::GoBase*> ( new TYPE( ) ); \
				} \
	/*! Copies an instance of TYPE \param Target The object data will be copied to. \param Base The object data will be copied from */\
	static void Copy( TYPE* Target, TYPE* Base ) { TYPE::Copy(Target, Base); }; \
	/*! Copies an instance of TYPE \param Target The object data will be copied to. \param Base The object data will be copied from */\
	static void CopyDef( Bubblewrap::Base::GoBase* Target, Bubblewrap::Base::GoBase* Base ) \
				{\
				HardTest( false, "Copying unimplemented class: "+ std::string( typeid( TYPE ).name() )); \
		TYPE* target = dynamic_cast<TYPE*>( Target ); \
		TYPE* base = dynamic_cast<TYPE*>( Base ); \
		Copy( target, base ); \
				} \
	/*! Returns the type name of the object. \returns Returns "NAME".*/\
	virtual std::string TypeName() \
				{\
		return #TYPENAME;\
				}

#define REGISTER_CLASS( REGISTER , CLASS )  REGISTER->RegisterCreator( #CLASS, &CLASS::Create, &CLASS::CreateJson, &CLASS::Copy );

#define EMPTY_POINTER( TYPE ) class TYPE; typedef DType<TYPE*, nullptr> TYPE ## P;

#define PROTECTED_READ_FIELD( TYPE, NAME ) protected: /*! Storage for NAME */ TYPE NAME ## _;  public: /*! Gets NAME \returns The current value of NAME */ TYPE Get ## NAME() { return NAME ## _; } 
#define PROTECTED_FIELD( TYPE, NAME ) protected: /*! Storage for NAME */ TYPE NAME ## _;  public: /*! Gets NAME \returns The current value of NAME */ TYPE Get ## NAME() { return NAME ## _; } /*! Sets the value of NAME. \param NAME New value of NAME */ void Set ## NAME( TYPE NAME ) { NAME ## _ = NAME; }
#define PROTECTED_DIRTY_FIELD( TYPE, NAME ) protected: /*! Storage for NAME */ TYPE NAME ## _;  public: /*! Gets NAME \returns The current value of NAME */ TYPE Get ## NAME() { return NAME ## _; } /*! Sets the value of NAME and sets the class to dirty. \param NAME New value of NAME */ void Set ## NAME( TYPE NAME ) { NAME ## _ = NAME; IsDirty_ = true; }
#define REQUIRED_LOAD( TYPE, NAME, JNAME ) AssertMessage( !Params[ #JNAME ].isNull(), std::string( #JNAME ) + std::string( " is required " ) ); NAME ## _ = Params[ #JNAME ]. as ## TYPE();
#define OPTIONAL_LOAD( TYPE, NAME, JNAME ) if ( !Params[ #JNAME ].isNull() ) NAME ## _ = Params[ #JNAME ]. as ## TYPE();
#define NAIVE_COPY( NAME ) Target-> ## NAME ## _ = Base-> ## NAME ## _;
#endif 