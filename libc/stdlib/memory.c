#include <stdlib.h>

#include "mimalloc.h"

_LIBC_EXPORT void *_LIBC_API malloc(size_t size)
{
    return calloc(1, size);
}

_LIBC_EXPORT void *_LIBC_API calloc(size_t count, size_t size)
{
    return mi_calloc(count, size);
}

_LIBC_EXPORT void *_LIBC_API realloc(void *block, size_t newSize)
{
    return mi_realloc(block, newSize);
}

_LIBC_EXPORT void _LIBC_API free(void *block)
{
    mi_free(block);
}

_LIBC_EXPORT void _LIBC_API free_aligned_sized(void *block, size_t alignment, size_t size)
{
    free(block);
}

_LIBC_EXPORT void _LIBC_API free_sized(void *block, size_t size)
{
    free(block);
}
