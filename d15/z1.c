#include "Fraction.h"

int main()
{
	Fraction a, b;
	fraction_scan(&a);
	fraction_scan(&b);
	fraction_print(fraction_sum(a, b));
	return 0;
}