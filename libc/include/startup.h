/// @file startup.h
///
/// @brief This file has definitions related to startup
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#include "libc.h"

/// @brief Whether libc is initialized
extern bool libcInitialized;

/// @brief Initialize libc
extern _LIBC_EXPORT void _LIBC_API _LibcInitialize(char* environment[]);

/// @brief Initialize platform-specific stuff
extern void _LIBC_API _LibcPlatformInitialize(void);

typedef int32_t(*PFN_MAIN)(int32_t argc, char* argv[]);
extern int32_t main(int32_t argc, char* argv[]);

/// @brief Call main
extern _LIBC_EXPORT int32_t _LIBC_API _LibcStartMain(PFN_MAIN main, int32_t argc, char* argv[]);
