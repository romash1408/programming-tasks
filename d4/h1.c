#include <stdio.h>
#include <math.h>

int main(int argc, char** argv)
{
    if(argc < 2)
    {
	printf("Пропущен первый аргумент: число, из которого требуется извлечь квадратный корень\n");
	exit(1);
    }
    
    const float D_MAX = 0.0000001;
    float n = atof(argv[1]);
    
    if(n < 0)
    {
	printf("Введено отрицательное число\n");
	exit(2);
    }
    
    int step = 0;
    float x = n, last = 0;
    while(fabs(x - last) >= D_MAX)
    {
	printf("%d: %.4f\n", ++step, x);
	last = x;
	x = (x + n / x) / 2;
    } 
    
    printf("√%.4f ~ %.4f\n", n, x);
    
    getchar();
    return 0;
}