#include <stdio.h>
#include <stdlib.h>

int *find_element(int *i, int *end, int find)
{
	for(; i != end; ++i)
	{
		if(*i == find) return i;
	}
	return 0;
}

int main()
{
	int n;
	printf("Enter array size: ");
	scanf("%d", &n);
	
	int *arr = malloc(n * sizeof(*arr));
	if(!arr)
	{
		printf("Memory error!\n");
		return 1;
	}
	
	printf("Enter array elements: ");
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
	}
	
	int find;
	printf("What element do you want to invert: ");
	scanf("%d", &find);
	
	int *found = find_element(arr, arr + n, find);
	if(!found)
	{
		printf("Element %d was not found...\n", find);
	}
	else
	{
		*found = (*found ^ (-1)) + 1;
	}
	
	printf("\nResult:");
	for(int i = 0; i < n; ++i)
	{
		printf(" %d", arr[i]);
	}
	
	return 0;
}