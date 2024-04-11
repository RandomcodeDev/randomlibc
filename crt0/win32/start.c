#include <stdlib.h>

#include "libc.h"
#include "startup.h"

void mainCRTStartup(void)
{
    _LibcInitialize(NULL);

    int32_t status = _LibcStartMain(main, 0, NULL);

    exit(status);
}
