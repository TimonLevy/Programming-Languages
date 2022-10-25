//	htoi.c
//	Programmer: Daniel L.

//	This program converts a hard-coded hex number to an interger and prints it.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define BASE		16
#define PREFLET		120
#define PREFNUM		1
#define PREFLEN		2
#define DOUBDIG		10


int htoi(char s[]);
void gnirtS(char* s, int n);


int main()
{
	char hex[] = "0x5 7C45";

	printf("%d\n", htoi(hex));
}


/* htoi: hex to int, this functions converts hex numbers to interger. */
int htoi(char s[])
{
	int i, j, sum;
	i = PREFLEN;
	sum = 0;

	// Check the prefix of the number.
	if (s[0] != '0' || (int)tolower(s[PREFNUM]) != PREFLET)
		return 0;

	// Count the amount of digits.
	i = strlen(s);

	// Calculate each char's value and add it to the sum.
	for (i = (i - PREFLEN + 1), j = PREFLEN ; i >= PREFLEN ; i--, j++)
	{
		if (isdigit(s[i]))
		{
			sum += pow(BASE, (j - PREFLEN)) * (s[i] - '0');
		}
		else if (s[i] >= 'a' && s[i] <= 'f')
		{
			sum += pow(BASE, (j - PREFLEN)) * ((s[i] - 'a') + DOUBDIG);
		}
		else if (s[i] >= 'A' && s[i] <= 'F')
		{
			sum += pow(BASE, (j - PREFLEN)) * ((s[i] - 'A') + DOUBDIG);
		}
		// Allow spaces but reverse counting to not affect base counting.
		else if (s[i] == ' ')
			j--;
		else
			return 0;
	}

	return sum;
}