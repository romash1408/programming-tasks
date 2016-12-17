#include <stdio.h>
#include <string.h>

char* string_suffix(char* src, int size)
{
	int n = strlen(src);
	if(size < n && size >= 0)
	{
		return src + n - size;
	}
	return src;
}

int main()
{
	printf("Enter string: ");
	char str[256];
	gets(str);
	
	printf("Enter suffix length: ");
	int s;
	scanf("%d", &s);
	
	printf("Suffix: %s\n", string_suffix(str, s));
	
	return 0;
}