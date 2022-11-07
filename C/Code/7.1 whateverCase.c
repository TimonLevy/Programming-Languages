//	whateverCase.c
//	Programmer:	Daniel L.

//	This program converts and giver argument string's case based on the amount of capital/lowercase letters in the invokation and prints it.
//	Actually realy cool.

#include <stdio.h>
#include <string.h>

#define	STRING		1
#define HELP		"/?"
#define NOARGS		1
#define	isUpper(x)	(x >= 'A' && x <= 'Z' ? 1 : 0)
#define	DIFF		('A' - 'a')

int main(int argc, char* argv[])
{
	
	// Help prompt.
	if (strcmp(argv[STRING], HELP) == 0)
	{
		printf("Convert string to case based on the amount of capital or lowercase letters in the invokation.\n\nEXAMPLE:\n\tuppercase:\tWHATEverCase string\n\tlowercase:\twhatevERcasE string\n\n");
		return 1;
	}
	
	// return if no arguments are given.
	if	(argc == NOARGS)
	{
		printf("missing arguments.\n\n");
		return 0;
	}
	
	int uppers, lowers, c, wishState, curState, state;
	uppers = lowers = 0;
	
	// Count the amount of upper and lower case letters.
	for(c = *argv[0]; c != EOF && c!= '\0'; c = *++argv[0])
	{
		state = isUpper(c);
		uppers += state;		// increment uppers if char is uppercase.
		lowers += 1 - state; 	// do not increment lowers is chare is uppercase.
	}

	wishState = (uppers > lowers ? 1 : 0); 	// A binary flag for conversion checking.
	
	// Print the string in the correct case.
	for(c = *argv[STRING]; c != EOF && c!= '\0'; c = *++argv[STRING])
	{
		
		// Get the case state for the current char.
		curState = isUpper(c);
		
		// Correct it accordingly.
		if(wishState != curState)
		{
			c += (curState == 1 ? -1 * DIFF : DIFF); // if uppercase deduct, otherwise add.
		}
		
		putchar(c);
	}
	
	// NULL-terminate the string.
	putchar('\0');
}
