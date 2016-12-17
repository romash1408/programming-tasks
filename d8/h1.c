#include <stdlib.h>
#include <stdio.h>

struct unit
{
	int val;
	struct unit 
		*parent,
		*left,
		*right;
};

void add(struct unit *tree, struct unit *adding)
{
	if(adding->val < tree->val)
	{
		if(tree->left)
		{
			add(tree->left, adding);
		}
		else
		{
			tree->left = adding;
			adding->parent = tree;
		}
	}
	else
	{
		if(tree->right)
		{
			add(tree->right, adding);
		}
		else
		{
			tree->right = adding;
			adding->parent = tree;
		}
	}
}

int* ascent(struct unit *tree, int *target)
{
	if(tree->left) target = ascent(tree->left, target);
	*target++ = tree->val;
	if(tree->right) target = ascent(tree->right, target);
	return target;
}

int main()
{
	int n, *a;
	struct unit **tree;
	printf("Введите количество чисел, которые хотите отсортировать: ");
	scanf("%d", &n);
	a = malloc(n * sizeof(*a));
	tree = malloc(n * sizeof(*tree));
	if(!a || !tree)
	{
		printf("Недостаточно памяти для заданного количества чисел. Программа будет остановлена...\n");
		return 1;
	}
	printf("Введите числа через пробел: ");
	for(int i = 0; i < n; ++i)
	{
		tree[i] = malloc(sizeof(**tree));
		scanf("%d", &tree[i]->val);
		tree[i]->left = tree[i]->right = 0;
		if(i != 0) add(tree[0], tree[i]);
	}
	
	//sorting
	ascent(tree[0], a);

	//show
	printf("Массив отсортирован: ");
	for(int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	
	free(a);
	for(int i = 0; i < n; ++i)
	{
		free(tree[i]);
	}
	free(tree);
	printf("\n");
	
	return 0;
}