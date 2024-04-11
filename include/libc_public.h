/// @file libc.h
///
/// @brief This file has global public definitions
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#ifdef _WIN32
#define _LIBC_API __cdecl

#ifdef _IN_LIBC
#define _LIBC_EXPORT __declspec(dllexport)
#else
#define _LIBC_EXPORT __declspec(dllimport)
#endif

// Stop vcruntime.h from trolling
#define _ACRTIMP _LIBC_EXPORT
#define _CRT_FUNCTIONS_REQUIRED 0

#ifdef _MSC_VER
#define _LIBC_REEXPORT(Old, New) __pragma("comment(linker, \"/export:" #New "=" #Old "\")")

#if _MSC_VER >= 1400 && __STDC_VERSION__ < 199000L
#define restrict __restrict
#else
#define restrict
#endif
#else
#endif
#elif defined __linux__
#define _LIBC_API __cdecl
#ifdef _IN_LIBC
#define _LIBC_EXPORT __attribute__((visibility("default")))
#endif
#endif

#ifdef __cplusplus
#define _LIBC_BEGIN_EXTERN_C                                                                                           \
    extern "C"                                                                                                         \
    {
#define _LIBC_END_EXTERN_C }
#else
#define _LIBC_BEGIN_EXTERN_C
#define _LIBC_END_EXTERN_C
#endif