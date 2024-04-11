/// @file libc.h
///
/// @brief This file has global internal definitions
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#include "libc_public.h"

#include <stdbool.h>
#include <stdint.h>

#ifdef _WIN32
#ifndef _LIBC_NO_PLATFORM_HEADER
#include "win32.h"
#endif
#endif
