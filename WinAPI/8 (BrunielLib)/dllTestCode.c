#include "Bruhniel.h"
#include <windows.h>

//#pragma comment( lib, "libBruhniel.lib" )
// gcc DllTest.c -LlbruhnieLib -o DllTest

typedef void (__stdcall *function)();

int main()
{
    function printWelcome;

    // Load the DLL and locate the function inside.
    HMODULE dll = LoadLibrary("libBruhniel.dll");
    printWelcome = (function)GetProcAddress(dll, "printWelcome");

    // Execute it.
    printWelcome();

    // Free the address space.
    FreeLibrary(dll);
}