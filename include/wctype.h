/// @file wctype.h
///
/// @brief This file contains definitions for wide character manipulation
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#include "libc_public.h"

#include <stddef.h>

_LIBC_BEGIN_EXTERN_C

extern _LIBC_EXPORT wchar_t _LIBC_API towupper(wchar_t c);
extern _LIBC_EXPORT wchar_t _LIBC_API towlower(wchar_t c);

_LIBC_END_EXTERN_C
