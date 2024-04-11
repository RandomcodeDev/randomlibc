/// @file win32.h
///
/// @brief This file has internal definitions and includes for Windows
///
/// @copyright (c) 2024 Randomcode Developers

#pragma once

#ifndef _WIN32
#error "This isn't Windows, don't include win32.h"
#endif

#include "phnt_windows.h"
#include "phnt.h"

extern IMAGE_DOS_HEADER __ImageBase;
