#include <stdio.h>

/* This program prints wether a character in a string is EOF or not. */

main()
{
	int c;

	while (c = getchar())
		printf("%s\n", ( c == EOF ) ? "1" : "0");
}