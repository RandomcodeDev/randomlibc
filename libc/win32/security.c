// Reverse engineered with ghidra combined with sources included in VS2022 (probably works, untested. Also seems to be present in
// ntdllp.lib)
//
// probably needs work for 32-bit support

#include "libc.h"
#include "misc.h"

// TODO: randomize
#ifdef _WIN64
#define SECURITY_COOKIE 0x6942069420694206
#else
#define SECURITY_COOKIE 0x69420694
#endif

UINT_PTR __security_cookie;
UINT_PTR __security_cookie_complement;

void __security_init_cookie(void)
{
    __security_cookie = SECURITY_COOKIE;
    DbgPrint("__security_cookie initialized to 0x%llX\n", __security_cookie);
}

void __security_check_cookie(UINT_PTR Cookie)
{
    _LibcAssert(Cookie == __security_cookie == SECURITY_COOKIE);
}

// TODO: implement these

void _RTC_Shutdown(void)
{
}
void _RTC_InitBase(void)
{
}
void _RTC_CheckStackVars(void)
{
}

void __GSHandlerCheckCommon(void *EstablisherFrame, void *DispatcherContext, unsigned int *GSHandlerData)

{
    uintptr_t uVar1;
    void *pvVar2;

    DbgPrint("__GSHandlerCheckCommon(EstablisherFrame = 0x%llX, DispatcherContext = 0x%llX, GSHandlerData = 0x%llX)\n",
             (uintptr_t)EstablisherFrame, (uintptr_t)DispatcherContext, (uintptr_t)GSHandlerData);

    /* WARNING: Load size is inaccurate */
    /* WARNING: Load size is inaccurate */
    pvVar2 = EstablisherFrame;
    if ((*GSHandlerData & 4) != 0)
    {
        pvVar2 = (void *)((intptr_t)*(int *)((intptr_t)GSHandlerData + 4) + (intptr_t)EstablisherFrame &
                          (intptr_t)-*(int *)((intptr_t)GSHandlerData + 8));
    }
    uVar1 = (uintptr_t)*(unsigned int *)(*(intptr_t *)((intptr_t)DispatcherContext + 0x10) + 8);
    if ((*(unsigned char *)(uVar1 + 3 + *(intptr_t *)((intptr_t)DispatcherContext + 8)) & 0xf) != 0)
    {
        EstablisherFrame =
            (void *)((intptr_t)EstablisherFrame +
                     (uintptr_t)(*(unsigned char *)(uVar1 + 3 +
                                                             *(intptr_t *)((intptr_t)DispatcherContext + 8)) &
                                          0xfffffff0));
    }
    __security_check_cookie((uintptr_t)EstablisherFrame ^
                            *(uintptr_t *)((intptr_t)(int)(*GSHandlerData & 0xfffffff8) + (intptr_t)pvVar2));
    return;
}

BOOLEAN __GSHandlerCheck(unsigned char ExceptionRecord, void *EstablisherFrame, unsigned char ContextRecord,
                               void *DispatcherContext)

{

    DbgPrint("__GSHandlerCheck(ExceptionRecord = 0x%llX, EstablisherFrame = 0x%llX, ContextRecord = 0x%llX, "
             "DispatcherContext = 0x%llX)\n",
             ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);

    __GSHandlerCheckCommon(EstablisherFrame, DispatcherContext, *(void **)((intptr_t)DispatcherContext + 0x38));
    return TRUE;
}

void __chkstk(uintptr_t address)
{
    DbgPrint("__chkstk(address = 0x%llX)\n", address);
}