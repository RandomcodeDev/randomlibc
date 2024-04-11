#pragma once

#include "libc_public.h"

#include <stdint.h>

typedef struct _FILE
{
    uint8_t *buffer;
    size_t bufferSize;

    int64_t writePosition;
    int64_t readPosition;

    void *handle;
} FILE;
