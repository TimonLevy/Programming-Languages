//	gnirtS.c
//	Programmer:	Daniel L.

//	This program gets an input and prints it in reverse.

#include <stdio.h>
#include <string.h>

#define TRUE 		1
#define MAXLINE		1000

void gnirtS(char* s);
int inpLine(char s[]);


int main()
{

	// Init string.
	char string[MAXLINE];

	// While True loop infinite loop.
	while (TRUE)
	{

		printf("This program reverse and input string.\n >  ");
		/* Get line from input using [Inpline()] into [string].
		   Input both string and string length into [gnirtS()]. */
		inpLine(string);
		gnirtS(string);
	}
}


/* gnirtS: Reverses a given string.*/
void gnirtS(char st[])
{
	int i, len = strlen(st);

	// Create a string in the length of the parameter string.
	char rev[len];

	// Run over the param string in reverse order and input it into [rev].
	for (i = len - 1 ; i >= 0 ; --i)
	{
		rev[(len - i - 1)] = st[i];
	}

	// Add a Null Terminator into [rev] and print it.
	rev[len] = '\0'; 
	printf("\n%s | %s\n", st, rev);
}


/* inpLine: read a line into s and return the pointer to s*/
int inpLine(char s[])
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
