//	eofOrNot.c
//	Programmer:	Daniel L.
//	
//	This program prints wether a character in a string is EOF or not.

#include <stdio.h>

int main()
{
	int c;

	// Recieve chars until interrupt.
	while (c = getchar())

		// Print 1 if [c] is EOF otherwise print 0.
		printf("%s\n", ( c == EOF ) ? "1" : "0");
}