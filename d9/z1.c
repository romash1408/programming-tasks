#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n, m;
	printf("Enter rows and cols number: ");
	if(scanf("%d%d", &n, &m) < 2 || n <= 0 || m <= 0)
	{
		printf("Error: rows and cols must be positive numbers");
		return 1;
	}
	int *a = malloc(n * m * sizeof(*a));
	if(!a)
	{
		printf("Memory error\n");
		return 2;
	}
	for(int k = 0; k < n * m; ++k)
	{
		int i = k / m;
		int j = (i % 2 == 0 ? k % m : m - k % m - 1);
		a[i * m + j] = k;
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			printf("%-4d", a[i * m + j]);
		}
		putchar('\n');
	}
	free(a);
	return 0;
}