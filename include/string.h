/// @file string.h
///
/// @brief This file contains definitions for manipulating strings and blocks of memory
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#include "libc_public.h"

_LIBC_BEGIN_EXTERN_C

extern _LIBC_EXPORT int _LIBC_API memcmp(const void *a, const void *b, size_t maxCount);
extern _LIBC_EXPORT int _LIBC_API strncmp(const char *a, const char *b, size_t maxCount);
extern _LIBC_EXPORT int _LIBC_API strcmp(const char *a, const char *b);

extern _LIBC_EXPORT void *_LIBC_API memcpy(void *restrict destination, void *restrict source, size_t maxCount);
extern _LIBC_EXPORT void *_LIBC_API memccpy(void *restrict a, void *restrict b, int c, size_t maxCount);

extern _LIBC_EXPORT size_t _LIBC_API strlen(const char *string);
extern _LIBC_EXPORT size_t _LIBC_API strnlen(const char *string, size_t maxCount);
extern _LIBC_EXPORT void *_LIBC_API memset(const void *dest, int value, size_t count);

_LIBC_END_EXTERN_C
