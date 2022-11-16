#include "Bruhniel.h"
#include <windows.h>

// gcc DllTest.c -LlbruhnieLib -o DllTest

typedef void (*function) (void);

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