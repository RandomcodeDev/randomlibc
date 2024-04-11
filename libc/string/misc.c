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

_LIBC_EXPORT void *_LIBC_API memset(const void *dest, int value, size_t count)
{
    size_t i;

    for (i = 0; i < count; i++)
    {
        ((uint8_t *)dest)[i] = (uint8_t)value;
    }

    return (void *)dest;
}
