#pragma once

#include "TwsApiL0.h"
#include "TwsApiDefs.h"
using namespace TwsApi; // for TwsApiDefs.h

//#pragma comment(lib,"WS2_32")


/*
	To get this working in the future....

	- use CMakeLists.txt to build to build32
	- add existing project "tws_cpp_api" from cmakebuilddir\Api\
	- reference tws_cpp_api proj from app
	- add additional include dirs for headers

	ADDNL INCLUDE DIRS:
		master\source\PosixClient\Shared
		master\TwsApiC++\Api

	re: pragma, https://stackoverflow.com/questions/16948064/unresolved-external-symbol-lnk2019/16948470

*/

const char* test_twsapi() {

	int a = 61919;

	EWrapperL0 mw(false);

	EClientL0* ec = EClientL0::New(&mw);

	const char* c = ec->apiVersion();
	//printf(c);

	//auto c = EClientL0(

	return c;

}


EClientL0* get_client() {

	int a = 61919;

	EWrapperL0 mw(false);

	EClientL0* ec = EClientL0::New(&mw);

	//const char* c = ec->apiVersion();
	//printf(c);

	//auto c = EClientL0(

	return ec;

}