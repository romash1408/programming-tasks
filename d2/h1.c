#include<stdio.h>

int main()
{
	int fahr, celsius;
	int lower, upper, step;
	step = 20;
	
	printf("Input lower and upper bound (°C):");
	scanf("%d %d", &lower, &upper);
	
	celsius = upper;
	
	printf(" ᵒC\t ᵒF\n");
	while(celsius >= lower)
	{
		fahr = celsius * 9 / 5 + 32;
		printf("%3d\t%3d\n", celsius, fahr);
		celsius -= step;
	}
	
	return 0;
}
