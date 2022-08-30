#include <stdio.h>

void CharGrapher();

int main()
{
	CharGrapher();
}


/* CharGrapher: Counts the amount of times a character appears in a given input.*/
void CharGrapher()
{
	int c;
	int nLetter[ASCIILEN];

	// Reset the array.
	for (int i = 0 ; i < ASCIILEN ; ++i)
	{
		nLetter[i] = 0;
	}

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