// 5.C
// 
// Programmer:      Daniel L.
// Date:            13/11/22
//
// This program takes a path as a parameter and copies 24 of it's first bytes into a new file.

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#define minArgs     2
#define pathIndex   1
#define bytesToRead 24
#define newFilePath "C:\\Users\\Cyber-Administrator\\Desktop\\Daniel - Repo\\WinAPI\\5\\5-new.txt"

int fileExists(TCHAR* a);

int main(int argc, char* argv[])
{
    if (argc < minArgs)
    {
        printf("missing arguents.\n\n5.exe\t[path]\n\n    path -  A path to a file.\n\n");
        return FALSE;
    }

    LPCTSTR path = argv[pathIndex];


    // Obtain a handle to the given path.
    HANDLE fileHandle = CreateFile(
        path,                                   /* lpFileName: The name of the file (path). */
        GENERIC_READ,                           /* dwDesiredAccess: The requested access permissions. */
        (FILE_SHARE_READ | FILE_SHARE_WRITE),   /* dwShareMode: Manage what permissions other files may have when the file is opened by the program. */
        NULL,                                   /* lpSecurityAttributes */
        OPEN_EXISTING,                          /* dwCreationDisposition: determine what action to take when opening a file. */
        FILE_ATTRIBUTE_NORMAL,                  /* dwFlagsAndAttributes: The files attributes and flags. */
        NULL                                    /* hTemplateFile */
    );


    // Check if the file exists.
    if (GetLastError() == ERROR_FILE_NOT_FOUND)
    {
        printf("[-] File \"%s\" was not found.\n\n", path);
        return FALSE;
    }
    else
        printf("[+] Found file \"%s\".\n", path);


    // Read 24 bytes from the file.
    BYTE arr[bytesToRead];
    LPDWORD bytesRead, bytesWritten;
    bytesRead = malloc(sizeof(LPDWORD));
    bytesWritten = malloc(sizeof(LPDWORD));

    BOOL res = ReadFile(
        fileHandle,                             /* hFile: A handle to the file. */
        arr,                                    /* lpBuffer: A buffer to output the read bytes to. */
        bytesToRead,                            /* nNumberOfBytesToRead: The amount of bytes to read from the file. */
        bytesRead,                              /* lpNumberOfBytesRead: The amount of bytes read. */
        NULL                                    /* lpOverlapped */
    );


    // If couldn't read, print a prompt and the error code.
    if ( res == FALSE )
    {
        printf("[-] Failed to read: %d\n\n", GetLastError());
        return FALSE;
    }
    else
        printf("[+] Successfuly read from file.\n");

    if ( *bytesRead != bytesToRead )
        printf("[?] Read only %d bytes from file. (Expected %d)\n", bytesRead, bytesToRead);


    // Create a new file to write to.
    HANDLE newFileHandle = CreateFile(
        newFilePath,                            /* lpFileName: The name of the file (path). */
        GENERIC_WRITE,                          /* dwDesiredAccess: The requested access permissions. */
        (FILE_SHARE_READ | FILE_SHARE_WRITE),   /* dwShareMode: Manage what permissions other files may have when the file is opened by the program. */
        NULL,                                   /* lpSecurityAttributes */
        CREATE_ALWAYS,                          /* dwCreationDisposition: determine what action to take when opening a file. */
        FILE_ATTRIBUTE_NORMAL,                  /* dwFlagsAndAttributes: The files attributes and flags. */
        NULL                                    /* hTemplateFile */
    );

    if ( GetLastError() == ERROR_ALREADY_EXISTS  )
        printf("[?] File already existed, overwrote it.\n");
    else if ( GetLastError() != 0)
    {
        printf("[-] Failed to create file: %d\n\n", GetLastError());
        return FALSE;
    }
    else
        printf("[+] Successfuly created file: %s\n", newFilePath);


    // Write to the new file.
    res = WriteFile(
        newFileHandle,                          /* hFile: A handle to the file. */
        arr,                                    /* lpBuffer: A buffer that contains the bytes to write. */
        bytesToRead,                            /* nNumberOfBytesToRead: The amount of bytes to write to the file. */
        bytesWritten,                           /* lpNumberOfBytesRead: The amount of bytes written. */
        NULL                                    /* lpOverlapped */
    );


    // If couldn't write, print a prompt and the error code.
    if ( res == FALSE )
    {
        printf("[-] Failed to write: %d\n\n", GetLastError());
        return FALSE;
    }
    else
        printf("[+] Successfuly wrote to file.\n");

    if ( *bytesRead != bytesToRead )
        printf("[?] Wrote only %d bytes to file. (Expected %d)\n", bytesWritten, bytesToRead);
    else
        printf("[+] Wrote %d bytes to file.\n", bytesToRead);

    // Done :)))
    printf("Done!!! :)\n\n");
}
