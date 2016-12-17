#include <stdio.h>
#include <ctype.h>

int main()
{
    const int MAX_SIZE = 256;
    
    int cur, count = 0, modified = 0;
    char* out = malloc(MAX_SIZE + 1);
    
    while((cur = getchar()) != EOF && count < MAX_SIZE)
    {
	modified += (cur >= 'a' && cur <= 'z');
	out[count++] = toupper(cur);
    }
    out[count] = 0;
    printf("\n%s\nModified %d characters", out, modified);
    
    return 0;
}