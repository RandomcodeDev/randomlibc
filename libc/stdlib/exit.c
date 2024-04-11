#include <stdlib.h>

#include "libc.h"
#include "misc.h"

_LIBC_EXPORT void _LIBC_API _Exit(int code)
{
    _LibcExit(code);
}

_LIBC_EXPORT void _LIBC_API exit(int code)
{
    _Exit(code);
}

_LIBC_EXPORT void _LIBC_API abort(void)
{
    _Exit(3);
}

_LIBC_EXPORT void _LIBC_API _LibcHandleAssert(int condition, const char* text)
{
    abort();
}