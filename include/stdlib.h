/// @file stdlib.h
///
/// @brief This file contains miscellaneous utilities
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#include "libc_public.h"

#include <stddef.h>

_LIBC_BEGIN_EXTERN_C

extern _LIBC_EXPORT int _LIBC_API atexit(void (*function)(void));
extern _LIBC_EXPORT void _LIBC_API _Exit(int code);
extern _LIBC_EXPORT void _LIBC_API exit(int code);
extern _LIBC_EXPORT void _LIBC_API abort(void);

extern _LIBC_EXPORT void *_LIBC_API malloc(size_t size);
extern _LIBC_EXPORT void *_LIBC_API calloc(size_t count, size_t size);
extern _LIBC_EXPORT void *_LIBC_API realloc(void *block, size_t newSize);
extern _LIBC_EXPORT void _LIBC_API free(void *block);
extern _LIBC_EXPORT void _LIBC_API free_aligned_sized(void *block, size_t alignment, size_t size);
extern _LIBC_EXPORT void _LIBC_API free_sized(void *block, size_t size);

_LIBC_END_EXTERN_C
