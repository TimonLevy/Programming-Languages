#include <stdio.h>

void ChaReplacer();

int main()
{
	ChaReplacer();
}


/* ChaReplacer: Replace all tab characters '    ' with \t, all backslashes '\' with \\ and all backspaces with \b.*/
void ChaReplacer()
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