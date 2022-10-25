//	nothingOnce.c
//	Programmer:	Daniel L.

//	replaces all continous blank space between words with a single space.

#include <stdio.h>
#define FALSE		0

int main()
{
	int blankFlag = FALSE, c;

	// Continously get input.
	while(c = getchar())
	{

		// Check if char is the first blankspace in the row.
		if (((c == ' ') || (c == '\t')) && (blankFlag == FALSE))
		{

			// Print a single space and disable the flag.
			putchar(' ');
			blankFlag = !blankFlag;
		}
		// Don't print if flag is disabled and blackspace detected.
		else if (((c == ' ') || (c == '\t')) && (blankFlag == TRUE))
			;
		// Print any other char and enable flag again.
		else
		{
			putchar(c);
			blankFlag = !blankFlag;
		}
	}
}