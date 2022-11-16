#include <windows.h>
#include <stdio.h>
#include "Bruhniel.h"

#define BUFFERSIZE		100

BOOL APIENTRY DllMain(
   HANDLE hModule,	   // Handle to DLL module 
   DWORD ul_reason_for_call, 
   LPVOID lpReserved )     // Reserved
{
   return TRUE;
}

// printfInput
// 
// Recieves:	None
// Returns:		None
//
// This function gets an input from the user and then printf it back to him, unicode oriented.
void printInput()
{
	short unsigned int i, c;
	TCHAR inputBuffer[BUFFERSIZE];

	for (i = 0; i < BUFFERSIZE - 1, (c = getchar()) != EOF, c != '\0', c != '\n'; inputBuffer[i++] = c)
		;
	inputBuffer[i] = '\0';

	printf(inputBuffer);
}

void printWelcome()
{
	printf("WELCOME DUDESSSSS\n");
}