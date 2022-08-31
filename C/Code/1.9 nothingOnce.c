#include <stdio.h>
#define FALSE		0

void nothingOnce();

int main()
{
	nothingOnce();
}


/* nothingOnce: replaces all continous blank space between words with a singular space.*/
void nothingOnce()
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