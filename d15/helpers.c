#include "helpers.h"

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int NOD(int a, int b)
{
	if(a == 0 && b == 0) return 1;
	if(a == 0) return b;
	if(b == 0) return a;
	if(a < 0) a = -a;
	if(b < 0) b = -b;
	
	if(a < b) swap(&a, &b);
	do
	{
		a %= b;
		swap(&a, &b);
	} while(b > 0);
	return a;
}