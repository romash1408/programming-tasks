#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char* str = malloc(101 * sizeof(*str)), n = 0;
	printf("Введите выражение: ");
	while(n < 100 && (str[n] = tolower(getchar())) != '\n')
	{
		if(str[n] != ' ') ++n;
	}

	int half = n / 2;
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
		printf("Введённая фраза является полиндромом\n");
	}
	else
	{
		printf("Введённая фраза не является полиндромом\n");
	}

	return 0;
}