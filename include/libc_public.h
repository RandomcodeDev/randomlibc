/// @file libc.h
///
/// @brief This file has global public definitions
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#ifdef _WIN32
#define _LIBC_API __fastcall

#ifdef _IN_LIBC
#define _LIBC_EXPORT __declspec(dllexport)
#else
#define _LIBC_EXPORT __declspec(dllimport)
#endif

#ifdef _MSC_VER
#define _LIBC_ALIAS(Old, New) __pragma("comment(linker, \"/alternatename:" #New "=" #Old "\")")
#else
#endif
#elif defined __linux__
#define _LIBC_API __fastcall
#ifdef _IN_LIBC
#define _LIBC_EXPORT __attribute__((visibility("default")))
#endif
#endif

#ifdef __cplusplus
#define _LIBC_BEGIN_EXTERN_C extern "C" {
#define _LIBC_END_EXTERN_C }
#else
#define _LIBC_BEGIN_EXTERN_C
#define _LIBC_END_EXTERN_C
#endif