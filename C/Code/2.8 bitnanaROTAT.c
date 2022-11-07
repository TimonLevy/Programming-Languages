//	bitnanaROTAT.c
//	Programmer:	Daniel L.

//	This programs rotates the bit of a hard-coded interger n times and 
//	prints the outcome.
//	https://www.youtube.com/watch?v=YGXCnZMGa6M

#include <stdio.h>

/*Noam's comments:
Great documention.
Your implemtation of rightrot doesn't work correctly it suppose to like this:
8 rotated right 4 times is 8
and
8 rotated right 8 times is 8
means that 8 is 1000 so 4 times is 0100,0010,0001,1000
means that 8 is 1000 so 8 times is 0100,0010,0001,1000,0100,0010,0001,1000
*/

unsigned int getbits(unsigned int x, int p, int n);
int rightrot(int s, int n);

int main()
{
	int num = 991;

	printf("%d\n", rightrot(num, 16));
}

/* rightrot: rotate the bits in the number to the right by [n]. */
int rightrot(int s, int n)
{
	int m, j, i;

	// Count the amount of bits.
	for (i = 1, j = s ; (j = j >> 1) > 0 ; i++)
		;
	
	// Get the amount of effetive rotation, that is dismiss all full rotations.
	m = (i > n ? n : (n % i));

	// Get the [m]th bit and all the following and space them out to fit the rest behind.
	j = getbits(s, (m - 1), m);
	j = j << (i - m);
	
	// Put the leftover bits behind the left-shifted "right" bits.
	return (j | (s >> m));
}


/* getbits: The function from the book 'Chapter 2.9'. */
unsigned int getbits(unsigned int x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
