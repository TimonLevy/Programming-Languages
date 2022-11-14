#include "BruhnieLib.h"
#include <stdio.h>
#include <TCHAR.h>

#define BUFFERSIZE		100


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

	_tprintf(inputBuffer);
}

void printWelcome()
{
	_tprintf(TEXT("WELCOME DUDESSSSS"));
}