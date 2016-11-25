#include <stdio.h>

void uniq_copy(int* a, int n, int* b, int* m)
{
	*m = 0;
	for(int i = 0; i < n; ++i)
	{
		if(*m == 0 || b[*m - 1] != a[i])
		{
			b[(*m)++] = a[i];
		}
	}
	return ;
}

int main()
{
	int array[100], n = 0, next;
	printf("Enter items: ");
	while(scanf("%d", &next) == 1)
	{
		array[n++] = next;
	}
	
	uniq_copy(array, n, array, &n);
	
	printf("Unique: ");
	for(int i = 0; i < n; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}