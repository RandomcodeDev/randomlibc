/// @file errno.h
///
/// @brief This file defines errno
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#include "libc_public.h"

_LIBC_BEGIN_EXTERN_C

#define EINVAL 1

extern _LIBC_EXPORT int errno;

_LIBC_END_EXTERN_C