/// @file wchar.h
///
/// @brief This file contains definitions for wide character/string manipulation
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#include "libc_public.h"

#include <stddef.h>

_LIBC_BEGIN_EXTERN_C

extern _LIBC_EXPORT int _LIBC_API wcscasecmp(const wchar_t* a, const wchar_t* b);
extern _LIBC_EXPORT int _LIBC_API wcsncasecmp(const wchar_t* a, const wchar_t* b, size_t count);

_LIBC_END_EXTERN_C
