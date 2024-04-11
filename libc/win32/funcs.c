#include <assert.h>
#include <wchar.h>

#include "libc.h"
#include "misc.h"

#include "win32/funcs.h"

PIMAGE_DOS_HEADER ntdll;

_LIBC_EXPORT NTSTATUS
(*NTAPI
    __imp_NtTerminateProcess)(
        _In_opt_ HANDLE ProcessHandle,
        _In_ NTSTATUS ExitStatus
        );
_LIBC_ALIAS(__imp_NtTerminateProcess, NtTerminateProcess);

void InitializeFunctionLoader(void)
{
    PPEB_LDR_DATA ldrData = NtCurrentPeb()->Ldr;
    for (PLIST_ENTRY current = &ldrData->InLoadOrderModuleList; current->Flink != &ldrData->InLoadOrderModuleList; current = current->Flink)
    {
        PLDR_DATA_TABLE_ENTRY entry = CONTAINING_RECORD(current, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);
        // TODO: handle alternate root drive letter?
        if (wcsncasecmp(entry->FullDllName.Buffer, L"C:\\Windows\\System32\\ntdll.dll", entry->FullDllName.Length) == 0)
        {
            ntdll = entry->DllBase;
            break;
        }
    }

    _LibcAssert(ntdll != NULL);
}
