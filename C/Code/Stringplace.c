#include <stdio.h>
#include <string.h>

#define TRUE		1
#define FALSE		0
#define ASCIILEN	128
#define LOWER		0
#define UPPER		300
#define STEP		20
#define FAHRSUB		32
#define FAHRMUL		(5.0/9.0)
#define MAXLINE		1000


void Ex8();
void Ex9();
void Ex10();
void Ex14();
void Ex15();
float fahrCalc(int x);
void Ex19(char* s, int n);
int inpline(char s[]);


/* Chapter 1:
	* Exercise 8
	* Exercise 9
	* Exercise 10
*/
int main()
{
	//Ex8();
	//Ex9();
	//Ex10();
	//Ex14();
	//Ex15();

	char string[MAXLINE];
	while (1)
	{
		Ex19(string, inpline(string));
	}
}


/* Ex8: Count all tab characters, Blank spaces and newline characters and print them.*/
void Ex8()
{
	int tabCount = 0, nlCount = 0, blankCount = 0, c;

	while ((c = getchar()) != EOF)
	{
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

	printf("Newlines: %d\nBlanks: %d\nTabs: %d\n", nlCount, blankCount, tabCount);
}


/* Ex9: replaces all continous blank space between words with a singular space.*/
void Ex9()
{
	int blankFlag = FALSE, c;

	while(c = getchar())
	{
		if ((c == ' ') && (blankFlag == FALSE))
		{
			printf(" ");
			blankFlag = TRUE;
		}
		else if ((c == ' ') && (blankFlag == TRUE))
			;
		else
		{
			printf("%c", c);
			blankFlag = FALSE;
		}
	}
}


/* Ex10: Replace all tab characters '    ' with \t, all backslashes '\' with \\ and all backspaces with \b.*/
void Ex10()
{
	int c;

	while ((c = getchar()) != EOF)
	{
		switch (c)
		{
			case '\t':
				printf("\\t");
				break;
			case '\b':
				printf("\\b");
				break;
			case '\\':
				printf("\\\\");
				break;
			default:
				printf("%c", c);
				break;
		}

	}
}


/* Ex14: Counts the amount of times a character appears in a given input.*/
void Ex14()
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


/* Ex15: Calculates the different temprature degree equivalent in steps of 20 using a function.*/
void Ex15()
{
	int fahr;

	for (fahr = LOWER ; fahr <= UPPER ; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, fahrCalc(fahr));
}


/* fahrCalc: Turns fahrenheit temprature degrees into Celsius.*/
float fahrCalc(int temp)
{
	return FAHRMUL * (temp - FAHRSUB);
}


/* Ex19: Reverses a given string.*/
void Ex19(char st[], int len)
{
	int i;
	char rev[len];

	for (i = len - 2 ; i >= 0 ; --i)
	{
		rev[(len - i - 2)] = st[i];
	}
	rev[len-1] = '\0'; 
	printf("\n%s : %s\n", st, rev);
}


/* inpline: read a line into s and return the pointer to s*/
int inpline(char s[])
{
	int c, i;

	for (i = 0 ; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n' ; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = '\0';
		++i;
	} 
	else
		s[i] = '\0';

	return i;
}