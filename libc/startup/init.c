#include "libc.h"
#include "startup.h"

bool libcInitialized;

_LIBC_EXPORT void _LIBC_API _LibcInitialize(char* environment[])
{
    _LibcPlatformInitialize();

    libcInitialized = true;
}

_LIBC_EXPORT int32_t _LIBC_API _LibcStartMain(PFN_MAIN main, int32_t argc, char* argv[])
{
    return main(argc, argv);
}
