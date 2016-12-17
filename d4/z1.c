#include <stdio.h>

int main()
{
    int count;
    printf("Введите количество лесенок: ");
    scanf("%d", &count);
    
    for(int spaces = count - 1; spaces >= 0; spaces--)
    {
	for(int i = 0; i < count; i++)
	{
	    printf("%c", (i < spaces ? ' ' : '#'));
	}
	printf("\n");
    }
    
    return 0;
} 
