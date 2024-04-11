#include "misc.h"
#include "libc.h"

void _LIBC_API _LibcExit(int code)
{
    NtTerminateProcess(NtCurrentProcess(), code);
}