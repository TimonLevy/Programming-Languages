//	charYeeter.c
//	Programmer:	Daniel L.

//	This program takes two hard-coded strings, subsitutes them and prints them.

#include <stdio.h>
#include <string.h>

void charYeeter(char a[], char b[]);

int main()
{
	char s1[] = "AAABBBBBB";
	char s2[] = "XAXXXBBXX";

	charYeeter(s1, s2);

	printf("%s | %s\n", s1, s2);
}


/* charYeeter: Delete all characters from [a] that match those of [b]. */
void charYeeter(char a[], char b[])
{
	int i, j;
	char c[strlen(a)];

	// Add all non-matching characters to a temporary string.
	i = j = 0;
	do
	{
		while ((a[i + 1] != '\0' && b[i + 1] != '\0') && (a[i] != b[i]))
		{	
			c[j++] = a[i++];
		}
	}while (a[i] != '\0' && b[++i] != '\0');
	c[--i] = '\0';

	// Copy them back into the original string.
	for (i = 0 ; i < j ; i++)
		a[i] = c[i];
	a[i] = '\0';
}