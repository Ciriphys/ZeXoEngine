#pragma once

#ifdef ZX_PLAT_WIN
	#ifdef ZX_BUILD_DLL
		#define ZX_API __declspec(dllexport)
	#else
		#define ZX_API __declspec(dllimport)
	#endif
#else
	#error ZeXo supports only Windows!
#endif