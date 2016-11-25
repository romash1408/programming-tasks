#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	printf("Enter sudoku rank: ");
	if(scanf("%d", &n) < 1 || n <= 0)
	{
		printf("Error: rank must be a positive number");
		return 1;
	}
	int n2 = n * n, found;
	int *a = malloc(n2 * n2 * sizeof(*a));
	char *b = malloc(n2 * sizeof(*b)), wrong = 0;
	if(!a || !b)
	{
		printf("Memory error\n");
		return 2;
	}
	
	printf("Enter sudoku:\n");
	for(int i = 0; i < n2; ++i)
	{
		memset(b, 0, n2 * sizeof(*b));
		found = 0;
		for(int j = 0; j < n2; ++j)
		{
			int val;
			scanf("%d", &val);
			if(val > 0 && val <= n2 && b[val - 1] == 0)
			{
				++found;
				b[val - 1] = 1;
			}
			a[i * n2 + j] = val;
		}
		if(found != n2) wrong = 1;
	}
	
	for(int j = 0; !wrong && j < n2; ++j)
	{
		memset(b, 0, n2 * sizeof(*b));
		found = 0;
		for(int i = 0; i < n2; ++i)
		{
			int val = a[i * n2 + j];
			if(val > 0 && val <= n2 && b[val - 1] == 0)
			{
				++found;
				b[val - 1] = 1;
			}
		}
		if(found != n2) wrong = 1;
	}
	
	for(int ki = 0; !wrong && ki < n; ++ki)
	{
		for(int kj = 0; !wrong && kj < n; ++kj)
		{
			memset(b, 0, n2 * sizeof(*b));
			found = 0;
			for(int i = 0; i < n; ++i)
			{
				for(int j = 0; j < n; ++j)
				{
					int val = a[(ki * n + i) * n2 + kj * n + j];
					if(val > 0 && val <= n2 && b[val - 1] == 0)
					{
						++found;
						b[val - 1] = 1;
					}
				}
			}
			if(found != n2) wrong = 1;
		}
	}
	
	if(wrong) printf("\nIncorrect\n");
	else printf("\nCorrect\n");
	
	free(a);
	free(b);
	return 0;
}