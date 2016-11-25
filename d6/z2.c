#include <stdio.h>

int main()
{
	int n;
	do
	{
		printf("Введите натуральное число: ");
	} while(scanf("%d", &n) != 1 || n <= 0);
	
	printf("\n%d = 1", n);
	
	int i = 2;
	for(; i <= n; )
	{
		if(n % i != 0) 
		{
			++i;
			continue ;
		}
		printf(" * %d", i);
		n /= i;
	}
	printf("\n");
	
	return 0;
}