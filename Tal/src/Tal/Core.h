#pragma once

#ifdef TAL_PLATFORM_WINDOWS
	#ifdef TAL_BUILD_DLL
		#define TAL_API __declspec(dllexport)
	#else
		#define TAL_API __declspec(dllimport)
	#endif
#else
	#error Tal supports only Windows for now
#endif // TAL_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
