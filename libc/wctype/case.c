#include <wctype.h>

#include "libc.h"

_LIBC_EXPORT wchar_t _LIBC_API towupper(wchar_t c)
{
    return c & ~(1 << 5);
}

_LIBC_EXPORT wchar_t _LIBC_API towlower(wchar_t c)
{
    return c | (1 << 5);
}