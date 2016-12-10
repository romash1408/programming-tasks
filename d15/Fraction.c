#include "Fraction.h"
#include <stdio.h>
#include "helpers.h"

static Fraction fraction_norm(Fraction a)
{
	int k = NOD(a.numerator, a.denomerator);
	a.numerator /= k;
	a.denomerator /= k;
	return a;
}

Fraction fraction_multiplication(Fraction a, Fraction b)
{
	return (Fraction){a.numerator * b.numerator, a.denomerator * b.denomerator};
}

Fraction fraction_sum(Fraction a, Fraction b)
{
	return fraction_norm((Fraction){a.numerator * b.denomerator + b.numerator * a.denomerator, a.denomerator * b.denomerator});
}

void fraction_scan(Fraction *a)
{
	scanf("%d/%d", &a->numerator, &a->denomerator);
}

void fraction_print(Fraction a)
{
	printf("%d/%d", a.numerator, a.denomerator);
}