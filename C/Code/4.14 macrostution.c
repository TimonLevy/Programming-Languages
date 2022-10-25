//	macrostution.c
//	Programmer:	Daniel L.

//	This program swaps the values of two variables using a macro then prints them.

#include <stdio.h>
#define swap(t, x, y) \		// swap the values of x and y, both must be of same type whch is t.
t temp = x; \
x = y; \
y = temp;

// Get two variables and substitute their values.
int main()
{
	char* a = "String One";
	char* b = "String Two";

	swap(char*, a, b);

	printf("a %s | b %s", a, b);
}