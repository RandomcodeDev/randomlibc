#include <wchar.h>

#include "libc.h"

_LIBC_EXPORT size_t _LIBC_API wcsnlen(const wchar_t *string, size_t maxCount)
{
    size_t length;

    length = 0;
    while (length < maxCount && string[length] != L'\0')
    {
        length++;
    }

    return length;
}

_LIBC_EXPORT size_t _LIBC_API wcslen(const wchar_t *string)
{
    return wcsnlen(string, SIZE_MAX);
}