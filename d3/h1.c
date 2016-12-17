#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;
	printf("Введите длинны сторон треугольника: ");
	scanf("%f %f %f", &a, &b, &c);
	
	float max = (a > b ? a : b);
	max = (max > c ? max : c);
	
	if(max >= a + b + c - max)
	{
		printf("Невозможно построить треугольник\n");
		return 1;
	}
	
	float p = (a + b + c) / 2;
	float s = sqrtf(p * (p - a) * (p - b) * (p - c));
	
	printf("Площадь заданного треугольника составляет %.3f\n",  s);
	return 0;
}