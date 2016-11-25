#include <stdio.h>

void swap_int(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int a = 1, *b = &a, e = 3;
	const int c = 2, *d = &c;
	printf("%p (b -> a): %d\n%p (d -> c): %d\n", b, a, d, c);
	d = &a;
	*b = c;
	printf("%p (d -> a): %d\n", d, a);
	
	printf("a = %d; e = %d\n", a, e);
	printf("Swap!\n");
	swap_int(&a, &e);
	printf("a = %d; e = %d\n", a, e);
	
	return 0;
}