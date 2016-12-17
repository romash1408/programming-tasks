#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

const int MAX_EXEC = 256;

struct GlobalArgs
{
	int debug;
	double delta;
} gArgs;
static const char* optString = "dD:";

double exec(char* str, int deep = 1);
void str_replace(const char* src, const char* dst, const int count,
	 const char* inp, char* out);
int incr(char* val, int n);

int main(int argc, char** argv)
{
	const int MAX_VARS = 10;
	
	gArgs.debug = 0;
	gArgs.delta = 0.001;
	int opt;
	while((opt = getopt(argc, argv, optString)) != -1)
	{
		switch(opt)
		{
		case 'd':
			gArgs.debug = 1;
			break;
		case 'D':
			gArgs.delta = atof(optarg);
		}
	}
	
	printf("Задайте равенство для проверки: ");
	char cur;
	char str[MAX_EXEC], replaced[MAX_EXEC];
	int n = 0;
	while(n < MAX_EXEC && (cur = getchar()) != '\n')
	{
		if(cur == ' ') continue ;
		str[n++] = cur;
	}
	str[n] = 0;
	
	char vars[MAX_VARS], values[MAX_VARS];
	printf("Введите через пробел не более %d переменных: ", MAX_VARS);
	n = 0;
	while(n < MAX_VARS && (cur = getchar()) != '\n')
	{
		if(cur == ' ') continue;
		values[n] = '0';
		vars[n++] = cur;
	}
	
	int allright = 0;
	do
	{
		str_replace(vars, values, n, str, replaced);
		if(exec(replaced))
		{
			str_replace(vars, values, n, str, replaced);
			printf("Решение №%d: %s", ++allright, replaced);
			printf("\n");
		}
	} while(!incr(values, n));
	printf("Количество найденных решений: %d\nКонец работы программы. Нажмите [ввод] для выхода...\n", allright);
	getchar();
	return 0;
}

int incr(char* val, int n)
{
	int ret = 1;
	for(int i = 0; ret && i < n; ++i)
	{
		if(val[i] < '9')
		{
			val[i]++;
			ret = 0;
		}
		else
		{
			val[i] = '0';
		}
	}
	return ret;
}

void str_replace(const char* src, const char* dst, const int count,
	 const char* inp, char* out)
{
	int i, j;
	for(i = 0; inp[i]; ++i)
	{
		int found = 0;
		for(j = 0; !found && j < count; ++j)
		{
			if(inp[i] != src[j]) continue;
			out[i] = dst[j];
			found = 1;
		}
		if(!found)
		{
			out[i] =  inp[i];
		}
	}
	out[i] = 0;
	if(gArgs.debug)
	{
		for(j = 0; j < count; ++j)
		{
			printf("%c = %c%s", src[j], dst[j], (j < count - 1 ? "; " : ":\n"));
		}
	}
}

double exec(char* str, int deep)
{
	if(gArgs.debug)
	{
		for(int i = 0; i < deep; ++i) printf("\t");
		printf("%s\n", str);
	}
	
	if(*str == '(' && str[strlen(str) - 1] == ')')
	{
		str++;
		str[strlen(str) - 1] = 0;
	}
	
	const char* opts = "=^*/+-";
	for(const char* o = opts; *o; ++o)
	{
		for(char* c = str; *c; ++c)
		{
			int brackets = 0;
			do
			{
				if(*c == '(') brackets++;
				if(*c == ')') brackets--;
			} while(brackets > 0 && *c++);
			
			if(*c == *o)
			{
				*c = 0;
				int divider;
				switch(*o)
				{
				case '=': return fabs(exec(str, deep+1) - exec(c+1, deep+1)) < gArgs.delta;
				case '^': return pow(exec(str, deep+1), exec(c+1, deep+1));
				case '*': return exec(str, deep+1) * exec(c+1, deep+1);
				case '/':
					divider = exec(c+1, deep+1);
					if(!divider)
					{
						printf("Обнаружена ошибка: деление на ноль");
						abort();
					}
					return exec(str, deep+1) / divider;
				case '+': return exec(str, deep+1) + exec(c+1, deep+1);
				case '-': return exec(str, deep+1) - exec(c+1, deep+1);
				}
			}
		}
	}
	return atof(str);
}