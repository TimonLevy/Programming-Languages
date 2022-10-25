//	whateverCase.c
//	Programmer:	Daniel L.

//	This program converts and giver argument string's case based on a given argument and prints it.
//	Actually realy cool.

#include <stdio.h>
#include <string.h>

#define UPPER		"upper"
#define	LOWER		"lower"
#define HELP		"/?"
#define	HELP2		"help"
#define	CASE		1
#define	STRING		2
#define	MINARGS		3
#define	isUpper(x)	(x >= 'A' && x <= 'Z' ? 1 : 0)
#define	isLower(x)	(x >= 'a' && x <= 'z' ? 1 : 0)
#define	DIFF		('a' - 'A')


int main(int argc, char* argv[])
{
	// Help prompt.
	if (strcmp(argv[CASE], HELP) == 0 || strcmp(argv[CASE], HELP2) == 0)
	{
		printf("Convert string to given case.\n\nCASE [case] string\n\n\tcase - either 'upper' or 'lower'. (case sensitive)\n\n");
		return 1;
	}
	// Check that all arguments were given.
	if (argc < MINARGS)
	{
		printf("Missing argmuents.");
		return 0;
	}

	int c;

	// Check if the given case was 'upper'.
	if (strcmp(argv[CASE], UPPER) == 0)
	{
		for(c = *argv[STRING] ; c != '\0' && c != EOF ; c = *++argv[STRING])

			//correct the case and print. This will only catch letters that are in the wrong case.
			putchar((isLower(c) ? (c - DIFF) : c));
	}
	// 'lower'case given.
	else if (strcmp(argv[CASE], LOWER) == 0)
	{
		for(c = *argv[STRING] ; c != '\0' && c != EOF ; c = *++argv[STRING])
			putchar((isUpper(c) ? (c + DIFF) : c));
	}
	else
	{
		printf("Invalid case %s.", argv[CASE]);
	}

	printf("\n\n");
}