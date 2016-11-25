#include <stdio.h>

int main()
{
	FILE* inp = fopen("knight.in", "r");
	int n, m;
	fscanf(inp, "%d %d", &n, &m);
	fclose(inp);
	
	int board[50 * 50];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			board[i * m + j] = 0;
		}
	}
	board[0] = 1;
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(board[i * m + j] == 0) continue ;
			if(i + 2 < n && j + 1 < m)
			{
				board[(i+2) * m + j+1] += board[i * m + j];
			}
			if(i +1 < n && j + 2 < m)
			{
				board[(i+1) * m + j+2] += board[i * m + j];
			}
		}
	}
	
	FILE* out = fopen("knight.out", "w");
	fprintf(out, "%d", board[n * m -1]);
	fclose(out);
	
	return 0;
}