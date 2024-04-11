#include <errno.h>
#include <stdlib.h>

#include "libc.h"
#include "misc.h"

typedef struct _ATEXIT_ENTRY
{
    struct _ATEXIT_ENTRY *nextEntry;
    void (*function)(void);
} ATEXIT_ENTRY, *PATEXIT_ENTRY;

// TODO: mutex
static PATEXIT_ENTRY atexitFunctions;

_LIBC_EXPORT int _LIBC_API atexit(void (*function)(void))
{
    PATEXIT_ENTRY entry;

    if (!function)
    {
        return EINVAL;
    }

    entry = calloc(1, sizeof(ATEXIT_ENTRY));
    if (!entry)
    {
        return errno;
    }

    entry->function = function;
    entry->nextEntry = atexitFunctions;
    atexitFunctions = entry;

    return 0;
}

_LIBC_EXPORT void _LIBC_API _Exit(int code)
{
    _LibcExit(code);
}

_LIBC_EXPORT void _LIBC_API exit(int code)
{
    PATEXIT_ENTRY current;

    for (current = atexitFunctions; current->nextEntry != NULL; current = current->nextEntry)
    {
        if (current->function)
        {
            current->function();
        }
    }

    _Exit(code);
}

_LIBC_EXPORT void _LIBC_API abort(void)
{
    _Exit(3);
}

_LIBC_EXPORT void _LIBC_API _LibcHandleAssert(int condition, const char *text)
{
    if (!condition)
    {
        abort();
    }
}