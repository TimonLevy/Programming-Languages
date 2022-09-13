#include <stdio.h>
#define swap(t, x, y) \
t temp = x; \
x = y; \
y = temp;

int main()
{
	char* a = "String One";
	char* b = "String Two";

	swap(char*, a, b);

	printf("a %s | b %s", a, b);
}