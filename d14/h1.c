#include <stdio.h>

typedef struct
{
	int army, heroes, resources, total;
} PS;

void print(const PS **p, const int n)
{
	printf("\n№   |Army  |Heroes  |Res. |Total   |\n");
	for(int i = 0; i < n; ++i)
	{
		printf("%4d|%6d|%8d|%5d|%8d|\n", i+1, p[i]->army, p[i]->heroes, p[i]->resources, p[i]->total);
	}
}

void intSort(const PS **p, const int n, const void *by)
{
	unsigned char offset = by - (void*)p;
	PS *tmp;
	
	for(int i = 0; i < n - 1; ++i)
	{
		for(int j = 0; j < n - i - 1; ++j)
		{
			if((int)((void*)(p + i) + offset) > (int)((void*)(p + i +1) + offset))
			{
				tmp = p[i];
				p[i] = p[i+1];
				p[i+1] = tmp;
			}
		}
	}
}

int main()
{
	printf("How many players:");
	int n;
	scanf("%d", &n);
	PS **players = malloc(n * sizeof(*players));
	for(int i = 0; i < n; ++i)
	{
		printf("\nplayer %d:", i+1);
		scanf("%d%d%d", &players[i]->army, &players[i]->heroes, &players[i]->resources);
		players[i]->total = players[i]->army + players[i]->heroes + players[i]->resources;
	}
	
	print(players, n);
	
	intSort(players, n, &players[0]->army);
	printf("Sorted by Army:");
	print(players, n);
	
	return 0;
}