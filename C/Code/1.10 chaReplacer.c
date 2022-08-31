#include <stdio.h>

void chaReplacer();

int main()
{
	chaReplacer();
}


/* chaReplacer: Replace all tab characters '    ' with \t, all backslashes '\' with \\ and all backspaces with \b.*/
void chaReplacer()
{
	int c;

	// Continously get input until interrupt.
	while ((c = getchar()) != EOF)
	{

		// Replace special chars with programming notation.
		switch (c)
		{
			case '\t':
				printf("\\t");
				break;
			case '\b':
				printf("\\b");
				break;
			case '\\':
				printf("\\\\");
				break;

			// Print normal chars.
			default:
				printf("%c", c);
				break;
		}

	}
}