#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n, m;
	printf("Enter row and cols: ");
	if(scanf("%d%d", &n, &m) < 2 || n <= 0 || m <= 0)
	{
		printf("Error: rows and cols must be positive numbers");
		return 1;
	}
	int *a = malloc((n + 1) * (m + 1) * sizeof(*a));
	if(!a)
	{
		printf("Memory error\n");
		return 2;
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			scanf("%d", a + i * (m + 1) + j);
			if(i == 0 || a[i * (m + 1) + j] > a[n * (m + 1) + j]) a[n * (m + 1) + j] = a[i * (m + 1) + j];
			if(j == 0 || a[i * (m + 1) + j] < a[i * (m + 1) + m]) a[i * (m + 1) + m] = a[i * (m + 1) + j];
		}
	}
	printf("Saddle points:\n");
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(a[i * (m + 1) + m] == a[n * (m + 1) + j]) printf("(%d, %d) = %d\n", i, j, a[i * (m + 1) + m]);
		}
	}
	free(a);
	return 0;
}