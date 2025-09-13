#pragma once

#ifdef KRN_PLATFORM_WINDOWS
// Made so when I start working on Windows,
// I won't have to manually add this everywhere where needs
// to be imported/exported

    #warning Windows builds was not tested propperly. Be cautious
    #ifdef KRN_BUILD_DLL
        #define KRN_API __declspec(dllexport)
    #else
        #define KRN_API __declspec(dllimport)
    #endif // KRN_BUILD_DLL

#elif defined(KRN_PLATFORM_LINUX)

    #define KRN_API

#else // KRN_PLATFORM_LINUX

    #error Not supported platform. Maybe it can be supported in the future

#endif // KRN_PLATFORM_WINDOWS
