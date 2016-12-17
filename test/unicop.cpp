#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>

const int n = 10;

int main()
{
	std::vector<int> in(n), out(n);
	
	for(int i = 0; i < n; ++i)
	{
		in[i] = (double)rand() / RAND_MAX * (n / 2);
		printf("%d ", in[i]);
	}
	printf("\n");
	
	int m = std::distance(out.begin(), std::unique_copy(in.begin(), in.end(), out.begin()));
	
	printf("Copied %d: ", m);
	for(int i = 0; i < m; ++i)
	{
		printf("%d ", out[i]);
	}
	
	return 0;
}