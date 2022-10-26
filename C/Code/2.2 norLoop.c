//	norLoop.c
//	Programmer:	Daniel L.

//	This program gets a new line and prints it.

#include <stdio.h>
#define MAXLINE		1000


void norLoop(char s[], int i);


int main()
{
	char string[MAXLINE];
	norLoop(string, MAXLINE);
	printf("%s\n", string);
}


/* notLoop: Performs the same loop that was written in the book without & or |, The loop just inputs a line into a buffer until newline or EOF are recieved. */
void norLoop(char s[], int lim)
{
	int i, c;

	for (i = 0 ; i < lim - 1 ; ++i)
	{
		
		// Break input if get newline/EOF.
		if ((c = getchar()) == '\n')
			break;
		if (c == EOF)
			break;
		s[i] = c;
	}

	// Add Null-Terminator to finish the string.
	s[i] = '\0';
}
