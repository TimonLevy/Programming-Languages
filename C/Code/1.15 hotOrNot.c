//	hotOrNot.c
//	Programmer:	Daniel L.

//	This program shows the fahrenheit and cellcius degrees in jumps of 20 from 0.

#include <stdio.h>
#define 	LOWER			0
#define 	UPPER			300
#define 	STEP			20	
#define		FAHRCALC(x)		(5.0/9.0) * (x - 32)	// Calculate the fahrenheit equivilant to the given cellcius degree.

void hotOrNot();
float fahrCalc(int a);

int main()
{
	hotOrNot();
}

/* hotOrNot: Calculates the different temprature degree equivalent in steps of 20 using a function.*/
void hotOrNot()
{
	int fahr;

	for (fahr = LOWER ; fahr <= UPPER ; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, fahrCalc(fahr));
}

/* fahrCalc: convert tepratures.*/
float fahrCalc(int temp)
{
	return FAHRCALC(temp);
}

