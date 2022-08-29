#include <stdio.h>

int main()
{
	double c;

	for (c = 0 ; getchar() != EOF ; ++c)
		;
	printf("%.0f\n", c);
} 