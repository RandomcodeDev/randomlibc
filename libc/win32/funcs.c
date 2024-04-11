// NOTE: this file could be replaced by just linking to kernel32, but this file is used instead because I'm just cool
// like that

#include <assert.h>
#include <wchar.h>

#include "libc.h"
#include "misc.h"

#include "win32/funcs.h"

PIMAGE_DOS_HEADER ntDll;

// scam the linker, and export so that other things can get at it
#define MAKE_FUNCTION_STUB(name)                                                                                       \
    void *__imp_##name;                                                                                               \
    _LIBC_REEXPORT(__imp_##name, name);

MAKE_FUNCTION_STUB(LdrGetProcedureAddress);
MAKE_FUNCTION_STUB(DbgPrint);
MAKE_FUNCTION_STUB(NtTerminateProcess);

#define GET_FUNCTION(dll, name)                                                                                        \
    _LibcAssert(NT_SUCCESS(LdrGetProcedureAddress((dll), &(ANSI_STRING)RTL_CONSTANT_STRING(#name), 0, &__imp_##name)))

static void GetNtDll(void)
{
    PPEB_LDR_DATA ldrData;
    PLIST_ENTRY current;
    PLDR_DATA_TABLE_ENTRY entry;

    ldrData = NtCurrentPeb()->Ldr;

    for (current = ldrData->InLoadOrderModuleList.Flink; current->Flink != &ldrData->InLoadOrderModuleList;
         current = current->Flink)
    {
        entry = CONTAINING_RECORD(current, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);

        // TODO: handle alternate root drive letter?
        if (wcsncasecmp(entry->FullDllName.Buffer, L"C:\\Windows\\System32\\ntdll.dll", entry->FullDllName.Length) == 0)
        {
            ntDll = entry->DllBase;
            break;
        }
    }

    _LibcAssert(ntDll != NULL);
}

static void GetLdrGetProcedureAddress(void)
{
    PIMAGE_NT_HEADERS ntHeaders;
    uint8_t *codeSection;
    PIMAGE_DATA_DIRECTORY exportDirectory;
    PIMAGE_EXPORT_DIRECTORY exports;
    uint64_t nameCount;
    uint64_t i;
    uint32_t *nameAddresses;
    uint16_t *ordinals;
    uint32_t *functions;
    const char *name;
    uint32_t function;

    ntHeaders = (PIMAGE_NT_HEADERS)((uint8_t *)ntDll + ntDll->e_lfanew);
    _LibcAssert(ntHeaders->Signature == IMAGE_NT_SIGNATURE);

    exportDirectory = &ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
    exports = (PIMAGE_EXPORT_DIRECTORY)((uint8_t *)ntDll + exportDirectory->VirtualAddress);

    nameCount = exports->NumberOfNames / sizeof(uint32_t);
    nameAddresses = (uint32_t *)((uint8_t *)ntDll + exports->AddressOfNames);
    ordinals = (uint16_t *)((uint8_t *)ntDll + exports->AddressOfNameOrdinals);
    functions = (uint32_t *)((uint8_t *)ntDll + exports->AddressOfFunctions);

    // TODO: use bsearch once it's implemented
    for (i = 0; i < nameCount; i++)
    {
        name = (const char *)((uint8_t *)ntDll + nameAddresses[i]);
        if (strcmp(name, "LdrGetProcedureAddress") == 0)
        {
            __imp_LdrGetProcedureAddress = (uint8_t *)ntDll + functions[ordinals[i]];

            break;
        }
    }

    _LibcAssert(__imp_LdrGetProcedureAddress != NULL);
}

void InitializeFunctionLoader(void)
{
    GetNtDll();
    GetLdrGetProcedureAddress();

    GET_FUNCTION(ntDll, NtTerminateProcess);
}
