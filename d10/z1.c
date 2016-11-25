#include <stdio.h>

int string_to_int(char *str)
{
	signed char sign = 1 - (*str == '-') * 2;
	if(*str == '+' || *str == '-') ++str;
	int ret = 0;
	while(*str != '\0' && *str != '\n' && *str != '.')
	{
		if(*str == ' ')
		{
			++str;
			continue;
		}
		if(*str < '0' || *str > '9') return 0;
		ret = 10 * ret + sign * (*str - '0');
		++str;
	}
	return ret;
}

int main()
{
	char* i;
	gets(i);
	printf("\nParsed: %d\n", string_to_int(i));
	
	return 0;
}