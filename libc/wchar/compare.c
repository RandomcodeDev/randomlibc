#include <string.h>
#include <wchar.h>
#include <wctype.h>

#include "libc.h"

_LIBC_EXPORT int _LIBC_API wcsncasecmp(const wchar_t *a, const wchar_t *b, size_t maxCount)
{
    size_t i;
    size_t aLength;
    size_t bLength;
    wchar_t ac;
    wchar_t bc;

    aLength = wcslen(a);
    if (aLength > maxCount)
    {
        aLength = maxCount;
    }

    bLength = wcslen(b);
    if (bLength > maxCount)
    {
        bLength = maxCount;
    }

    if (aLength != bLength)
    {
        return -1;
    }

    for (i = 0; i < maxCount && i < aLength && i < bLength; i++)
    {
        ac = towupper(a[i]);
        bc = towupper(b[i]);

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

_LIBC_EXPORT int _LIBC_API wcscasecmp(const wchar_t *a, const wchar_t *b)
{
    return wcsncasecmp(a, b, wcslen(a));
}
