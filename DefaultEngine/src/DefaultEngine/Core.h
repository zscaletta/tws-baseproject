#pragma once

#ifdef DE_PLATFORM_WINDOWS
	#ifdef DE_BUILD_DLL
		#define DefaultEngine_API __declspec(dllexport)
	#else
		#define DefaultEngine_API __declspec(dllimport)
	#endif
#else
	#error DefaultEngine only supports Windows!
#endif