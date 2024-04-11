#include "libc.h"
#include "startup.h"

#include "win32/funcs.h"

void _LIBC_API _LibcPlatformInitialize(void)
{
    InitializeFunctionLoader();
}
