#include <string.h>

#include "libc.h"

_LIBC_EXPORT size_t _LIBC_API strnlen(const char *string, size_t maxCount)
{
    size_t length;

    length = 0;
    while (length < maxCount && string[length] != '\0')
    {
        length++;
    }

    return length;
}

_LIBC_EXPORT size_t _LIBC_API strlen(const char *string)
{
    return strnlen(string, SIZE_MAX);
}
