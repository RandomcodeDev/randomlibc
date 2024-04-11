#include "libc.h"
#include "misc.h"

void _LIBC_API _LibcExit(int code)
{
    NtTerminateProcess(NtCurrentProcess(), code);
}