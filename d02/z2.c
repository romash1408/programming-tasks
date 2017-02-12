#include<stdio.h>

int main()
{
	int fahr, celsius;
	int lower, upper, step;
	step = 20;
	
	printf("Input lower and upper bound (°F):");
	scanf("%d %d", &lower, &upper);
	
	fahr = upper;
	
	printf(" ᵒF\t ᵒC\n");
	while(fahr >= lower)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%3d\t%3d\n", fahr, celsius);
		fahr -= step;
	}
	
	return 0;
}
