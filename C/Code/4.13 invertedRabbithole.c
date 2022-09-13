#include <stdio.h>
#include <string.h>
#define		MAXLINE 100

void invertedRabbithole(char s[], int d);


int main()
{
	// Get a line from input.
	char s[MAXLINE];
	int c, sp = 0;

	printf("input a line below to be reversed:\n");
	while (((sp + 1) < MAXLINE) && (s[sp++] = c = getchar()) != '\0' && (c != '\n'))
		;
	s[sp] = '\0';

	// Invert the string.
	invertedRabbithole(s, 0);

	// Print it.
	printf(s);
}


/* invertedRabbithole: reverse string [str] using recursion. */
void invertedRabbithole(char str[], int depth)
{

	// Save the current char in a temp variable.
	char temp = str[depth];
	if (temp == '\0')
		return;

	// Get length and the mirror position int he array.
	int len = strlen(str);
	int invertp = (len - depth - 1);

	// Recurse.
	invertedRabbithole(str, ++depth);

	// Switch the positions of the letters.
	str[invertp] = temp;
}