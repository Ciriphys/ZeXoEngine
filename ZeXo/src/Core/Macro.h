#pragma once

#ifdef ZX_PLAT_WIN
	#ifdef ZX_BUILD_DLL
		#define ZX_API __declspec(dllexport)
	#else
		#define ZX_API __declspec(dllimport)
	#endif
	
	#ifdef ZX_DEBUG
		#define ZX_ASSERT(condition, ...) if(!(condition)) { ZX_CORE_LOGGER_ERROR(__VA_ARGS__); __debugbreak(); }
 	#else	
		#define ZX_ASSERT(condition, ...)
	#endif

#else
	#error ZeXo supports only Windows!
#endif
