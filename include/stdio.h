/// @file stdio.h
///
/// @brief This file contains definitions related to I/O
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#include "libc_public.h"

_LIBC_BEGIN_EXTERN_C

typedef struct _FILE FILE;

extern _LIBC_EXPORT FILE *stdin;
extern _LIBC_EXPORT FILE *stdout;
extern _LIBC_EXPORT FILE *stderr;

extern _LIBC_EXPORT size_t _LIBC_API fwrite(const void *restrict data, size_t size, size_t count, FILE *restrict file);

_LIBC_END_EXTERN_C
