#include <stdio.h>

unsigned int getbits(unsigned int x, int p, int n);
int rightrot(int s, int n);

int main()
{
	int num = 991;

	printf("%d\n", rightrot(num, 5));
}

/* rightrot: rotate the bits in the number to the right by [n]. */
int rightrot(int s, int n)
{
	int j, i;
	j = s;

	// Count the amount of bits.
	for (i = 1 ; (j = j >> 1) > 0 ; i++)
		;

	// Get the [n]th bit and all the following and space them out to fit the rest behind.
	j = getbits(s, (n - 1), n);
	j = j << (i - n);
	
	// Put the leftover bits behind the left-shifted "right" bits.
	return (j | (s >> n));
}


/* getbits: The function from the book 'Chapter 2.9'. */
unsigned int getbits(unsigned int x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}