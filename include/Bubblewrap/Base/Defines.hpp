#ifndef DEFINES_H
#define DEFINES_H

#include "DType.hpp"
#include "Bubblewrap/Logs/StaticLog.hpp"
#include "Json/Json.h"

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
		Logs::StaticLog::Instance()->WriteLine( "Creating unimplemented class: " + std::string(#TYPENAME) ); \
		return static_cast<Bubblewrap::Base::GoBase*> ( new TYPE( ) ); \
				} \
	static void Copy( TYPE* Target, TYPE* Base ) { TYPE::Copy(Target, Base); }; \
	static void CopyDef( Bubblewrap::Base::GoBase* Target, Bubblewrap::Base::GoBase* Base ) \
				{\
		Logs::StaticLog::Instance()->WriteLine( "Copying unimplemented class: " + std::string(#TYPENAME) ); \
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

#endif 