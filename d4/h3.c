#include <stdio.h>

int main()
{
    char* values[2];
    values[0] = "не спринадлежит";
    values[1] = "принадлежит";
    
    float n;
    printf("Введите число для проверки на принадлежность интервалам: ");
    scanf("%f", &n);
    
    printf("%.2f %s [0; +inf)\n", n, values[n >= 0]);
    printf("%.2f %s [5; 15]\n", n, values[n >= 5 && n <= 15]);
    printf("%.2f %s (-1; 1)\n", n, values[n > -1 && n < 1]);
    printf("%.2f %s (-1; 1) U [5; 15)\n", n, values[n > -1 && n < 1 || n >= 5 && n < 15]);
    printf("%.2f %s (-1; 1) U [5; 15) U {20, 100, 1000}\n", n, values[n > -1 && n < 1 || n >= 5 && n < 15 || n == 20 || n == 100 || n == 1000]);
    
    return 0;
}