#ifndef FRACTION_H
#define FRACTION_H

typedef struct
{
	int numerator, denomerator;
} Fraction;

Fraction fraction_sum(Fraction, Fraction);

void fraction_scan(Fraction *);

void fraction_print(Fraction);

#endif /*FRACTION_H*/