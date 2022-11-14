// 7.C
//
// Programmer:          Daniel L.
// Date:                14/11/22
//
// This program creates a persistency by adding 'calc.exe' to HKLM Run on the registry.

// gcc 7.c -o 7.exe -l advapi32

#pragma comment( lib, "advapi32.lib" )

#include <windows.h>
#include <winbase.h>
#include <stdio.h>
#include <TCHAR.h>

#define persistentPath  (L##"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run")

int main()
{
    PHKEY   root;
    LPTSTR  buffer;

    _tprintf(TEXT("F1\n"));

    // Connect to the local regitstry.
    DWORD res = RegConnectRegistry(
        NULL,                                                                   // The name of the remote computer, if NULL use the local computer.
        HKEY_LOCAL_MACHINE,                                                     // The registry key to connect to.
        root                                                                    // The handle buffer to output to.
    );

    _tprintf(TEXT("F3\n"));

    // Check if the function succeed.
    if (res == ERROR_SUCCESS)
        _tprintf(TEXT("[+] Successfuly connected to the regitry.\n"));
    else
    {
        FormatMessage(
            (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER),      // dwFlags: Formatting options.
            NULL,                                                               // lpSource: The location of the message definition, ignored.
            res,                                                                // dwMessageId: The message identifier (error code).
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),                          // dwLanguageId: The language identifier for the formatted string.
            (LPTSTR)&buffer,                                                    // lpBuffer: The buffer to output the message to.
            0,                                                                  // nSize: The minimum amount of TCHARs to allocate to the output buffer.
            NULL                                                                // Args: An array of arguments to insert to the formatted message.
        );

        _tprintf(TEXT("[-] Failed to connect to the registry: %s\n\n"), buffer);
        return FALSE;
    }
}