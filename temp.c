#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahrenheitToCelsius(float fahr)
{
	return (5.0/9.0)*(fahr - 32.0);
}

float celsiusToFahrenheit(float cels)
{
	return (9.0/5.0)*cels + 32.0;
}

int main()
{
	float fahr, cels;

	printf("%3s %6s\n", "F", "C");

	for (fahr=UPPER; fahr>=LOWER; fahr -= STEP)
	{
		printf("%3.0f %6.1f\n", fahr, fahrenheitToCelsius(fahr));
	}

	printf("\n%3s %6s\n", "C", "F");
	for (cels=LOWER; cels<=UPPER; cels += STEP)
	{
		printf("%3.0f %6.1f\n", cels, celsiusToFahrenheit(cels));
	}
	return 0;
}