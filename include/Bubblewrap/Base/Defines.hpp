#ifndef DEFINES_H
#define DEFINES_H

#include "DType.hpp"
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
	}

#define REGISTER_CLASS( REGISTER , CLASS )  REGISTER->RegisterCreator( #CLASS, &CLASS::Create, &CLASS::CreateJson, &CLASS::Copy );

#define EMPTY_POINTER( TYPE ) class TYPE; typedef DType<TYPE*, nullptr> TYPE ## P;

#endif 