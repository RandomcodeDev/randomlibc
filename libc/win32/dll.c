#include "libc.h"
#include "startup.h"

BOOL WINAPI _DllMainCRTStartup(HINSTANCE dll, uint32_t reason, void* reserved)
{
    if (!libcInitialized)
    {
        _LibcInitialize(NULL);
    }

    return TRUE;
}
