#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);
float getFloat(float*);

int main()
{
	float placeholder = 0;
	getFloat(&placeholder);
	printf("%f\n", placeholder);
}

/* getFloat: get the next floaf from input into *pn. */
float getFloat(float *pn)
{
	int c, sign;

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
	return c;
} 