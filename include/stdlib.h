/// @file stdlib.h
///
/// @brief This file contains miscellaneous utilities
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#include "libc_public.h"

extern _LIBC_EXPORT void _LIBC_API _Exit(int code);
extern _LIBC_EXPORT void _LIBC_API exit(int code);
extern _LIBC_EXPORT void _LIBC_API abort(void);
