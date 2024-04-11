/// @file libc.h
///
/// @brief This file has miscellaneous internal definitions
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#include <assert.h>

#define _LibcAssert(condition) _LibcHandleAssert((condition), #condition)

extern void _LIBC_API _LibcExit(int code);
