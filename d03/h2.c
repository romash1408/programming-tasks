#include <stdio.h>

int main()
{
	const char WORD_SIZE = 128;
	
	printf("Oct\tDec\tHex\tChar\n");
	for (char i = 0; i < WORD_SIZE; i++)
	{
		printf("%8o%8d%8x%8c\n", i, i, i, i);
	}
	
	return 0;
}