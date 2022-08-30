#include <stdio.h>
#define LOWER		0
#define UPPER		300
#define STEP		20
#define FAHRSUB		32
#define FAHRMUL		(5.0/9.0)

void HotOrNot();
float fahrCalc();

int main()
{
	HotOrNot();
}

/* HotOrNot: Calculates the different temprature degree equivalent in steps of 20 using a function.*/
void HotOrNot()
{
	int fahr;

	for (fahr = LOWER ; fahr <= UPPER ; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, fahrCalc(fahr));
}


/* fahrCalc: Turns fahrenheit temprature degrees into Celsius.*/
float fahrCalc(int temp)
{
	return FAHRMUL * (temp - FAHRSUB);
}