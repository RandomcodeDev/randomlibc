#include <string.h>

#include "libc.h"

_LIBC_EXPORT void *_LIBC_API memcpy(void *restrict destination, void *restrict source, size_t maxCount)
{
    size_t i;

    for (i = 0; i < maxCount; i++)
    {
        ((uint8_t *)destination)[i] = ((uint8_t *)source)[i];
    }

    return destination;
}

_LIBC_EXPORT void *_LIBC_API memccpy(void *restrict destination, void *restrict source, int c, size_t maxCount)
{
    size_t i;

    for (i = 0; i < maxCount && ((uint8_t *)source)[i] != c; i++)
    {
        ((uint8_t *)destination)[i] = ((uint8_t *)source)[i];
    }

    return destination;
}