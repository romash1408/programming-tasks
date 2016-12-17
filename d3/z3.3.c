#include <stdio.h>

int main()
{
	char simb;	

	printf("Введите символ в нижнем регистре: \n");
	scanf("%c", &simb);
	if(simb >= 0x61 && simb <= 0x7a)
	{
		simb = simb - 0x20;
		printf("Введённый символ в верхнем регистре: %c\n", simb);
	}
	else
	{
		printf("Вы ввели символ в верхем регистре");
	}
	
	return 0;
}
