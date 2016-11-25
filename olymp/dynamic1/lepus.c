#include <stdio.h>

int main()
{
	FILE* inp = fopen("lepus.in", "r");
	int n;
	fscanf(inp, "%d\n", &n);
	int road[10000];
	for(int i = 0; i < n; i++)
	{
		fscanf(inp, "%c", road + i);
	}
	fclose(inp);
	
	road[n-1] = 0;
	for(int i = n - 2; i >= 0; --i)
	{
		if(road[i] == 'w')
		{
			road[i] = -1;
			continue ;
		}
		int max = -1;
		for(int step = 1; step <= 5; step += 2)
		{
			if(i + step < n && road[i + step] > max)
			{
				 max = road[i + step];
			}
		}
		road[i] = max + (max >= 0 && road[i] == '"');
	}
	
	FILE* out = fopen("lepus.out", "w");
	fprintf(out, "%d", road[0]);
	fclose(out);
	
	return 0;
}