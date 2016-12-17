#include <stdio.h>
#include <ctype.h>

int main()
{
    int symbol = 0,
    vowe = 0,
	digit = 0,
	mark = 0,
	letter = 0,
	inp;
	
	printf("Введите произвольный текст. Для окончания ввода дважды [CTRL+D]\n");
	while((inp = getchar()) != EOF)
	{
		++symbol;
		if(isalpha(inp)) ++letter;
		if(isdigit(inp)) ++digit;
		if(ispunct(inp)) ++mark;
		inp = tolower(inp);
		switch(inp)
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			++vowe;
		}
	}
	
	printf("\nИз %d введённых символов\n", symbol);
	printf("Гласных букв: %d\n", vowe);
	printf("Цифр: %d\n", digit);
	printf("Знаков препинания: %d\n", mark);
	printf("%d%c сиволов - буквенные\n", letter * 100 / symbol, '%');
	return 0;
}