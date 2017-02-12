#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n, *a;
	printf("Введите длинну рельефа: ");
	scanf("%d", &n);
	a = malloc((n + 2) * sizeof(*a));
	if(!a)
	{
		printf("Недостаточно памяти...\n");
		return 1;
	}

	printf("Введите высоты рельефа через пробел: ");
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}
	
	int topLeft = 0, topRight = 0, left = 0, right = n - 1, count = 0;
	while(left <= right)
	{
		if(topLeft < topRight)
		{
			if(a[left] != topLeft)
			{
				if(a[left] > topLeft)
				{
					topLeft = a[left];
				}
				else
				{
					count += topLeft - a[left];
				}
			}
			++left;
		}
		else
		{
			if(a[right] != topRight)
			{
				if(a[right] > topRight)
				{
					topRight = a[right];
				}
				else
				{
					count += topRight - a[right];
				}
			}
			--right;
		}
		printf("(%d) %d - %d (%d)\n", topLeft, left, right, topRight);
	}

	printf("Глубина лужи: %d\n", count);

	free(a);

	return 0;
}