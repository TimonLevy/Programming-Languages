//	chaReplacer.c
//	Programmer: Daniel L.

//	Replace all tab characters '    ' with \t, all backslashes '\' with \\ and all backspaces with \b.

#include <stdio.h>

int main()
{
	int c;

	printf("This program replaces all 'tabs', 'backslashes' and 'backspaces' with \\t, \\\\ and \\b.\n");
	printf("Enter input: ");

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