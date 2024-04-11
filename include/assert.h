/// @file assert.h
///
/// @brief This file defines assert
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#include "libc_public.h"

extern _LIBC_EXPORT void _LIBC_API _LibcHandleAssert(int condition, const char *text);

#ifdef NDEBUG
#define assert(condition) ((void)0)
#else
#define assert(condition) _LibcHandleAssert((condition), #condition);
#endif
