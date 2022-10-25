//	getFloat.c
//	Programmer:	Daniel L.

//	This program gets a float value from input and prints it.

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);
void getFloat(float*);

int main()
{
	float flt;
	getFloat(&flt);
	printf("%f\n", flt);
}

/* getFloat: get the next float from input into *pn. */
void getFloat(float *pn)
{
	int c, sign;
	*pn = 0;

	// Get rid of whitespace.
	while (isspace(c = getch()))
		;

	// Not a number.
	if (!isdigit(c) && c != EOF && c!= '+' && c != '-' && c!= '.')
	{
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	// Skip the sign char.
	if (c == '+' || c == '-')
		c = getch();

	// Get all the exponent digits.
	for (*pn = 0 ; isdigit(c) ; c = getch())
		*pn = 10 * *pn + (c - '0');

	// Toggle sign, negativ/positive.
	*pn *= sign;

	// Get the beginning of the remainder.
	if (c == '.')
	{

		// Add the remainder.
		c = getch();
		for (float remainderi = 0.1 ; isdigit(c) ; c = getch(), remainderi /= 10)
			*pn += (c - '0') * remainderi;
	}
	else if (c != EOF)
		ungetch(c);
} 