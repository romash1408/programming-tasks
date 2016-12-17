#include <stdio.h>
#include <ctype.h>

int main()
{
    const char FIRST = 'A', LAST = 'Z';
    char n;
    
    printf("Lower letter: ");
    scanf("%c", &n);
    
    if(n >= 'a' && n <= 'z')
    {
	n += 'A' - 'a';
    }
    
    if(n < FIRST || n > LAST)
    {
	printf("Wrang letter!\n");
	exit(1);
    }
    
    int side = n - FIRST;
    for(char row = FIRST; row <= n; ++row)
    {
	for(int i = -side; i <= side; i++)
	{
	    char si = row + (i < 0 ? i : -i);
	    printf("%c", (si < FIRST ? ' ' : si));
	}
	printf("\n");
    }
    
    return 0;
}