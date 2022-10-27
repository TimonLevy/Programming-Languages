//	charYeeter.c
//	Programmer:	Daniel L.

//	This program takes two hard-coded strings, subsitutes them and prints them.

#include <stdio.h>
#include <string.h>

void charYeeter(char a[], char b[]);
void charYeeter2(char a[], char b[]);

int main()
{
	char s1[] = "AACBBCBBC";
	char s2[] = "AAXBXBBXX";

	charYeeter2(s1, s2);

	printf("%s | %s\n", s1, s2);
}


/* charYeeter2: Delete all characters from [a] that match those of [b]. */
void charYeeter2(char a[], char b[])
{
	int i, j;

	for(i = j = 0 ; a[i] != '\0', b[i] != '\0' ; j++, i++)
	{
		for(; a[i] != b[i] ; a[i-j] = a[i], i++)
			;
	}

	a[i-j] = '\0';
}