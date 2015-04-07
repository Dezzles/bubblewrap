#ifndef DEFINES_H
#define DEFINES_H

#include "DType.hpp"
#include "Bubblewrap/Logs/StaticLog.hpp"
#include "Json/Json.h"
#include "Bubblewrap/Base/Assert.hpp"

#define CREATE_REGISTER(TYPE)  	static Bubblewrap::Base::GoBase* CreateJson( Json::Value Params ) \
		{ \
		Bubblewrap::Base::GoBase* Ret = static_cast<Bubblewrap::Base::GoBase*>( new TYPE () ); \
		return Ret; \
		} \
	static Bubblewrap::Base::GoBase* Create( ) \
		{ \
	return static_cast<Bubblewrap::Base::GoBase*> ( new TYPE( ) ); \
		} \
	static void Copy( TYPE* Target, TYPE* Base ); \
	static void CopyDef( Bubblewrap::Base::GoBase* Target, Bubblewrap::Base::GoBase* Base ) \
		{\
		TYPE* target = dynamic_cast<TYPE*>( Target ); \
		TYPE* base = dynamic_cast<TYPE*>( Base ); \
	Copy( target, base ); \
		} \
	virtual std::string TypeName() \
		{\
		return #TYPE;\
		}
#define CREATE_REGISTER_OVERRIDE(TYPE, FAKENAME)  	static Bubblewrap::Base::GoBase* CreateJson( Json::Value Params ) \
				{ \
		Bubblewrap::Base::GoBase* Ret = static_cast<Bubblewrap::Base::GoBase*>( new TYPE () ); \
		return Ret; \
				} \
	static Bubblewrap::Base::GoBase* Create( ) \
				{ \
	return static_cast<Bubblewrap::Base::GoBase*> ( new TYPE( ) ); \
				} \
	static void Copy( TYPE* Target, TYPE* Base ); \
	static void CopyDef( Bubblewrap::Base::GoBase* Target, Bubblewrap::Base::GoBase* Base ) \
				{\
		TYPE* target = dynamic_cast<TYPE*>( Target ); \
		TYPE* base = dynamic_cast<TYPE*>( Base ); \
	Copy( target, base ); \
				} \
	virtual std::string TypeName() \
				{\
		return #FAKENAME;\
				}

#define CREATE_REGISTER_DISABLED(TYPE, TYPENAME)  	static Bubblewrap::Base::GoBase* CreateJson( Json::Value Params ) \
				{ \
		Bubblewrap::Base::GoBase* Ret = static_cast<Bubblewrap::Base::GoBase*>( new TYPE () ); \
		return Ret; \
				} \
	static Bubblewrap::Base::GoBase* Create( ) \
				{ \
				HardTest( false, "Creating unimplemented class: "+ std::string( typeid( TYPE ).name() )); \
		return static_cast<Bubblewrap::Base::GoBase*> ( new TYPE( ) ); \
				} \
	static void Copy( TYPE* Target, TYPE* Base ) { TYPE::Copy(Target, Base); }; \
	static void CopyDef( Bubblewrap::Base::GoBase* Target, Bubblewrap::Base::GoBase* Base ) \
				{\
				HardTest( false, "Copying unimplemented class: "+ std::string( typeid( TYPE ).name() )); \
		TYPE* target = dynamic_cast<TYPE*>( Target ); \
		TYPE* base = dynamic_cast<TYPE*>( Base ); \
		Copy( target, base ); \
				} \
	virtual std::string TypeName() \
				{\
		return #TYPENAME;\
				}

#define REGISTER_CLASS( REGISTER , CLASS )  REGISTER->RegisterCreator( #CLASS, &CLASS::Create, &CLASS::CreateJson, &CLASS::Copy );

#define EMPTY_POINTER( TYPE ) class TYPE; typedef DType<TYPE*, nullptr> TYPE ## P;

#define PROTECTED_FIELD( TYPE, NAME ) protected: TYPE NAME ## _; public: TYPE Get ## NAME() { return NAME ## _; } void Set ## NAME( TYPE NAME ) { NAME ## _ = NAME; }
#define PROTECTED_DIRTY_FIELD( TYPE, NAME ) protected: TYPE NAME ## _; public: TYPE Get ## NAME() { return NAME ## _; } void Set ## NAME( TYPE NAME ) { NAME ## _ = NAME; IsDirty_ = true; }
#define REQUIRED_LOAD( TYPE, NAME, JNAME ) AssertMessage( !Params[ #JNAME ].isNull(), std::string( #JNAME ) + std::string( " is required " ) ); NAME ## _ = Params[ #JNAME ]. as ## TYPE();
#define OPTIONAL_LOAD( TYPE, NAME, JNAME ) if ( !Params[ #JNAME ].isNull() ) NAME ## _ = Params[ #JNAME ]. as ## TYPE();
#define NAIVE_COPY( NAME ) Target-> ## NAME ## _ = Base-> ## NAME ## _;
#endif 