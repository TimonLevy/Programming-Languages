#include <stdio.h>

void starGazer();


int main()
{
	starGazer();
}


/* starGazer: Count all tab characters, Blank spaces and newline characters and print them.*/
void starGazer()
{
	int tabCount, nlCount, blankCount, c;
	tabCount = nlCount = blankCount = 0;

	// Continously get input until interrupt.
	while ((c = getchar()) != EOF)
	{

		// Count occurances.
		switch (c)
		{
			case '\t':
				++tabCount;
				break;
			case ' ':
				++blankCount;
				break;
			case '\n':
				++nlCount;
				break;
		}

	}

	printf("Newlines:\t%6d\nBlanks:\t%6d\nTabs:\t%6d\n", nlCount, blankCount, tabCount);
}