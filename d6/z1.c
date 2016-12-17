#include <stdio.h>

int main()
{
	const int n = 10000;
	
	int cur = 2;
	for(; cur <= n; ++cur)
	{
		int sum = 0;
		for(int del = 1; del < cur; ++del)
		{
			if(cur % del == 0)
			{
				sum += del;
			}
		}
		if(sum == cur)
		{
			printf("%d\n", cur);
		}
	}
	
	return 0;
}