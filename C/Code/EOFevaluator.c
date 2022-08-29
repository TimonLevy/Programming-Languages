#include <stdio.h>

/* This program prints wether a character in a string is EOF or not. */

main()
{
	char st[] = {'a', 'b', 'c', 'd'};

	for (int l = 0 ; l <= sizeof(st) ; l++)
		printf("%d | %c, %s\n", l, st[l], (st[l] == '\0') ? "1, char is EOF" : "0, char is not EOF");
}