#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int army, heroes, resources, total;
} PS;

void print(const PS **p, const int n)
{
	printf("\nN   |Army  |Heroes  |Res. |Total   |\n");
	for(int i = 0; i < n; ++i)
	{
		printf("%4d|%6d|%8d|%5d|%8d|\n", i+1, p[i]->army, p[i]->heroes, p[i]->resources, p[i]->total);
	}
}

void intSort(const PS **p, const int n, const void *by)
{
	unsigned char offset = by - (void*)p[0];
	const PS *tmp;
	
	for(int i = 0; i < n - 1; ++i)
	{
		for(int j = 0; j < n - i - 1; ++j)
		{
			if(*(int*)((void*)p[j] + offset) > *(int*)((void*)p[j + 1] + offset))
			{
				tmp = p[j];
				p[j] = p[j+1];
				p[j+1] = tmp;
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
		players[i] = malloc(sizeof(*players[i]));
		scanf("%d%d%d", &players[i]->army, &players[i]->heroes, &players[i]->resources);
		players[i]->total = players[i]->army + players[i]->heroes + players[i]->resources;
	}
	
	print(players, n);
	
	intSort(players, n, &players[0]->army);
	printf("Sorted by Army:");
	print(players, n);
	
	intSort(players, n, &players[0]->heroes);
	printf("Sorted by Heroes:");
	print(players, n);
	
	intSort(players, n, &players[0]->resources);
	printf("Sorted by Resources:");
	print(players, n);
	
	intSort(players, n, &players[0]->total);
	printf("Sorted by Total:");
	print(players, n);
	
	return 0;
}