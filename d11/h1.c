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

int string_copy_safe(const char* src, const size_t size, char* dst)
{
	size_t i = 0;
	for(; i < size; ++i)
	{
		if(!src[i]) break;
		dst[i] = src[i];
	}
	dst[i] = 0;
	return i;
}

int string_concat_safe(const char* src1, const size_t size1, const char* src2, const size_t size2, char* dst)
{
	int ret = string_copy_safe(src1, size1, dst);
	return ret + string_copy_safe(src2, size2, dst + ret);
}

int main()
{
	char first[] = {'L', 'a', 'l', 'a', '!'},
		second[3],
		test[256];
	
	string_copy(first, test);
	//string_copy_safe(first, sizeof(first), test);
	printf("%s\n", test);
	
	string_concat(first, second, test);
	//string_concat_safe(first, sizeof(first), second, sizeof(second), test);
	printf("%s\n", test);
	
	return 0;
}