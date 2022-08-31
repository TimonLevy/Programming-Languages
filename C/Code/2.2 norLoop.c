#include <stdio.h>
#define MAXLINE		1000


void norLoop(char s[], int i);


int main()
{
	char string[MAXLINE];
	norLoop(string, MAXLINE);
	printf("%s\n", string);
}


void norLoop(char s[], int lim)
{
	int i, c;

	for (i = 0 ; i < lim - 1 ; ++i)
	{
		if ((c = getchar()) == '\n')
			break;
		if (c == EOF)
			break;
		s[i] = c;
	}

	s[i] = '\0';
}