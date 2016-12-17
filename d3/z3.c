#include <stdio.h>

int main()
{
	float fahr, celsius;
	float lower, upper, step;
	step = 20.0;
	
	printf("Input lower and upper bound (°F):");
	scanf("%f %f", &lower, &upper);
	
	fahr = upper;
	
	printf("       ᵒF       ᵒC\n");
	while(fahr >= lower)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%9.4f%9.4f\n", fahr, celsius);
		fahr -= step;
	}
	
	return 0;
}
