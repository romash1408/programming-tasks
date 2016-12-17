#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	float b, q;
	printf("Первый элемент прогрессии: ");
	scanf("%f", &b);
	printf("Коэффициент прогрессии: ");
	do
	{
		scanf("%f", &q);
	} while(q == 1);
	do
	{
		printf("Количество элементов: ");
		scanf("%d", &n);
	} while(n <= 0);
	
	printf("Сумма первых %d членов прогрессии равна: %.3f\n",
		n,
		b * (1 - pow(q, n)) / (1 - q)
	);
	
	return 0;
}