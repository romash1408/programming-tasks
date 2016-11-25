#include <stdio.h>
#include <math.h>

const float eps = 0.0001;

float f(float x)
{
	return tan(2.0*x + 1.0) - 1.0;
}

int main()
{
	float x0 = 0.1;
	int i = 0;
	
	while(fabs(f(x0)) > eps)
	{
		printf("Iteration %d: %.4f\n", i++, x0);
		float k = (f(x0 + eps) - f(x0)) / eps;
		x0 = (x0 * k - f(x0)) / k;
	}
	printf("Answer: %.4f", x0);
	
	return 0;
}