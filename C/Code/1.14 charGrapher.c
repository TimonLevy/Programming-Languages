//	charGrapher.c
//	Programmer:	Daniel L.

//	Counts the amount of times a character appears in a given input.

#include <stdio.h>

int main()
{

	// Create an array to count all the letter occurances.
	int c;
	int nLetter[ASCIILEN] = {0};

	printf("This program counts the amount of times each letter has been submitted and shows a histogram of the tally.\n");
	printf(" >>  ");

	// Count all the letters.
	while ((c = getchar()) != EOF)
	{
		nLetter[c] = nLetter[c] + 1;
	}

	// Print histogram.
	for (int i = 0 ; i < ASCIILEN ; ++i)
	{
		printf("[%3d] [%0*d]\n", i, nLetter[i], 0);
	} 
}