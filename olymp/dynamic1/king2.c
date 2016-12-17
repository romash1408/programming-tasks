#include <stdio.h>

int min(int a, int b, int c)
{
	if(a < b && a < c) return a;
	if(b < c && b < a) return b;
	return c;
}

int main()
{
	const int n = 8;
	
	FILE* inp = fopen("king2.in", "r");
	int board[n * n];
	for(int i = 0; i < n * n; ++i)
	{
		fscanf(inp, "%d", board + i);
	}
	fclose(inp);
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = n-1; j >= 0; --j)
		{
			int min = -1;
			if(j < n-1 && (min < 0 || board[i * n + j+1] < min))
				min = board[i * n + j+1];
			if(i > 0  && (min < 0 || board[(i-1) * n + j] < min))
				min = board[(i-1) * n + j];
			if(j < n-1 && i > 0 && (min < 0 || board[(i-1) * n + j+1] < min))
				min = board[(i-1) * n + j+1];
			if(min > 0)
				board[i * n + j] += min;
		}
	}
	
	FILE* out = fopen("king2.out", "w");
	fprintf(out, "%d", board[n * (n - 1)]);
	fclose(out);
	
	return 0;
}