#include <stdio.h>

void min_max_elems(int* a, int n, int* min, int* max)
{
	if(n <= 0) return ;
	*min = *max = *a;
	for(--n; n > 0; --n)
	{
		if(a[n] > *max) *max = a[n];
		else if(a[n] < *min) *min = a[n];
	}
	return ;
}

int main()
{
	int array[] = {5, 6, 2, -6, 10, -4, 8, 3, 1, 12}, a, b;
	min_max_elems(array, sizeof(array) / sizeof(*array), &a, &b);
	printf("min: %d; max: %d\n", a, b);
	return 0;
}