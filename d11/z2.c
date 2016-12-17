#include <stdio.h>

void string_copy(const char* src, char* dst)
{
	do
	{
		*dst++ = *src++;
	}
	while(*src);
}

void string_concat(const char* src1, const char* src2, char* dst)
{
	while(*src1)
	{
		*dst++ = *src1++;
	}
	string_copy(src2, dst);
}

int main()
{
	char *first = "La la la!", *second = "Azazaz :P", test[256];
	
	string_copy(first, test);
	printf("%s\n", test);
	
	string_concat(first, second, test);
	printf("%s\n", test);
	
	return 0;
}