/// @file funcs.h
///
/// @brief This file has definitions for the Windows function loader
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#ifndef _WIN32
#error "This isn't Windows, don't include win32/funcs.h"
#endif

#include "libc.h"

extern void InitializeFunctionLoader(void);
