#include <stdio.h>

int main()
{
    int min, max, inp, count = 0;
    
    printf("Вводите целые числа. В конце последовательности введите q для получения минимума и максимума последовательности\n");
    
    while(scanf("%d", &inp))
    {
	if(count++ == 0)
	{
	    min = inp;
	    max = inp;
	    continue ;
	}
	if(inp < min)
	{
	    min = inp;
	}
	if(inp > max)
	{
	    max = inp;
	}
    }
    
    if(count != 0)
    {
	printf("Минимум: %d\nМаксимум: %d\n", min, max);
    }
    
    return 0;
}