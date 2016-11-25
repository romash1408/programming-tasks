#include <stdio.h>

int main()
{
	FILE* inp = fopen("ladder.in", "r");
	int n;
	fscanf(inp, "%d", &n);
	int* ladder = malloc((n + 1) * sizeof(*ladder));
	ladder[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		fscanf(inp, "%d", ladder + i);
	}
	fclose(inp);
	
	ladder[n-1] += ladder[n];
	for(int i = n - 2; i >= 0; --i)
	{
		if(ladder[i + 1] > ladder[i + 2])
		{
			ladder[i] += ladder[i + 1];
		}
		else
		{
			ladder[i] += ladder[i + 2];
		}
	}
	
	FILE* out = fopen("ladder.out", "w");
	fprintf(out, "%d", ladder[0]);
	fclose(out);
	free(ladder);
	
	return 0;
}