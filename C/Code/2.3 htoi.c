//	htoi.c
//	Programmer: Daniel L.

//	This program converts a hard-coded hex number to an interger and prints it.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define BASE		16
#define	S_PREFIX		"0x"
#define	B_PREFIX		"0X"
#define PREFLEN		2
#define DOUBDIG		10


int htoi(char s[]);
void gnirtS(char* s, int n);


int main()
{
	char hex[] = "A";

	printf("%d\n", htoi(hex));
}


/* htoi: hex to int, this functions converts hex numbers to interger. */
int htoi(char s[])
{
	int i, j, sum = 0, offset = 0;
	char prefcheck[PREFLEN + 1];
	memcpy(prefcheck, s, PREFLEN);
	prefcheck[PREFLEN] = '\0';

	// Check the prefix of the number.
	if (strcmp(prefcheck, B_PREFIX) == 0 || strcmp(prefcheck, S_PREFIX) == 0)
		offset = PREFLEN;

	// Calculate each char's value and add it to the sum.
	for (i = (strlen(s) - 1), j = offset ; i >= offset ; i--, j++)
	{
		if (isdigit(s[i]))
			sum += pow(BASE, (j - offset)) * (s[i] - '0');
		
		else if (s[i] >= 'a' && s[i] <= 'f')
			sum += pow(BASE, (j - offset)) * ((s[i] - 'a') + DOUBDIG);
		
		else if (s[i] >= 'A' && s[i] <= 'F')
			sum += pow(BASE, (j - offset)) * ((s[i] - 'A') + DOUBDIG);
		
		// Allow spaces but reverse counting to not affect base counting.
		else if (s[i] == ' ')
			j--;
		else
			return 0;
	}

	return sum;
}