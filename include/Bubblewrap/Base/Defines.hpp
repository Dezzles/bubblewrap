#ifndef DEFINES_H
#define DEFINES_H

#include "DType.hpp"


#define CREATE_REGISTER(TYPE)  	static GoBase* CreateJson( Json::Value Params ) \
	{ \
		return new TYPE( Params ); \
	} \
	static GoBase* Create( ) \
	{ \
	return new TYPE( ); \
	} 

#define REGISTER_CLASS( REGISTER , CLASS )  REGISTER->RegisterCreator( #CLASS, &CLASS::Create, &CLASS::CreateJson );

#define EMPTY_POINTER( TYPE ) class TYPE; typedef DType<TYPE*, nullptr> TYPE ## P;

#endif 