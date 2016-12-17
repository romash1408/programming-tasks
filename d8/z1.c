#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n, *a;
	printf("Введите количество чисел, которые хотите отсортировать: ");
	scanf("%d", &n);
	a = malloc(n * sizeof(*a));
	if(!a)
	{
		printf("Недостаточно памяти для заданного количества чисел. Программа будет остановлена...\n");
		return 1;
	}
	printf("Введите числа через пробел: ");
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}

	//sorting
	int count = 0;
	for(int i = n - 1; i > 0; --i)
	{
		char flag = 0;
		for(int j = 0; j < i; ++j)
		{
			++count;
			if(a[j] > a[j + 1])
			{
				flag = 1;
				a[j] ^= a[j + 1];
				a[j + 1] ^= a[j];
				a[j] ^= a[j + 1];
			}
		}
		if(flag == 0) break ;
	}

	//show
	printf("Массив отсортирован за %d итераций: ", count);
	for(int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	free(a);
	printf("\n");

	return 0;
}