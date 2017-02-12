#include <stdio.h>
#include <string.h>

int main()
{
	char* str;
	printf("Введите слово: ");
	scanf("%s", str);
	int n = strlen(str), half = n / 2;
	char flag = 1;
	for(int i = 0; i < half; ++i)
	{
		if(str[i] != str[n - i - 1])
		{
			flag = 0;
			break;
		}
	}
	if(flag)
	{
		printf("Введённое слово является полиндромом\n");
	}
	else
	{
		printf("Введённое слово не является полиндромом\n");
	}

	return 0;
}