#include <stdio.h>

#define TRUE 		1
#define ASCIILEN	128
#define MAXLINE		1000

void gnirtS(char* s, int n);
int InpLine(char s[]);


int main()
{

	// Init string.
	char string[MAXLINE];

	// While True loop infinite loop.
	while (TRUE)
	{
		/* Get line from input using [Inpline()] into [string].
		   Input both string and string length into [gnirtS()]. */
		gnirtS(string, InpLine(string));
	}
}


/* gnirtS: Reverses a given string.*/
void gnirtS(char st[], int len)
{
	int i;

	// Create a string in the length of the parameter string.
	char rev[len];

	// Run over the param string in reverse order and input it into [rev].
	for (i = len - 2 ; i >= 0 ; --i)
	{
		rev[(len - i - 2)] = st[i];
	}

	// Add a Null Terminator into [rev] and print it.
	rev[len-1] = '\0'; 
	printf("\n%s | %s\n", st, rev);
}


/* InpLine: read a line into s and return the pointer to s*/
int InpLine(char s[])
{
	int c, i;

	// Get [MAXLINE] characters and put them into [s].
	for (i = 0 ; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n' ; ++i)
		s[i] = c;

	// Check if ENTER was recieved as an input to end input.
	if (c == '\n')
	{

		// Add Null Terminator.
		s[i] = '\0';
		++i;
	}

	// Check if input was interrupted without ENTER.
	else

		// Add Null terminator.
		s[i] = '\0';

	// Return the length of the string.
	return i;
}