#include <string.h>

#include "libc.h"

_LIBC_EXPORT int _LIBC_API memcmp(const void *a, const void *b, size_t maxCount)
{
    size_t i;
    uint8_t ac;
    uint8_t bc;

    for (i = 0; i < maxCount; i++)
    {
        ac = ((uint8_t *)a)[i];
        bc = ((uint8_t *)b)[i];

        if (ac < bc)
        {
            return -1;
        }
        else if (ac > bc)
        {
            return 1;
        }
    }

    return 0;
}

_LIBC_EXPORT int _LIBC_API strncmp(const char* a, const char* b, size_t maxCount)
{
    size_t aLength;
    size_t bLength;

    aLength = strlen(a);
    if (aLength > maxCount)
    {
        aLength = maxCount;
    }

    bLength = strlen(b);
    if (bLength > maxCount)
    {
        bLength = maxCount;
    }

    if (aLength != bLength)
    {
        return -1;
    }

    return memcmp(a, b, aLength);
}

_LIBC_EXPORT int _LIBC_API strcmp(const char* a, const char* b)
{
    return strncmp(a, b, SIZE_MAX);
}