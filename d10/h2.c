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

signed char add(struct unit *parent, int val, struct unit *place)
{
	if(parent == place)
	{
		place->val = val;
		place->left = place->right = place->parent = 0;
		return 1;
	}
	if(val == parent->val) return 0;
	if(val > parent->val)
	{
		if(parent->right != 0)
		{
			return add(parent->right, val, place);
		}
		place->val = val;
		place->left = place->right = 0;
		place->parent = parent;
		parent->right = place;
		return 1;
	}
	else
	{
		if(parent->left != 0)
		{
			return add(parent->left, val, place);
		}
		place->val = val;
		place->left = place->right = 0;
		place->parent = parent;
		parent->left = place;
		return 1;
	}
}

void unique_copy_unstable(int* a, int n, int* b, int* m)
{
	struct unit *sorted = malloc(n * sizeof(*sorted));
	*m = 0;
	for(int i = 0; i < n; ++i)
	{
		if(add(sorted, a[i], sorted + *m))
		{
			b[(*m)++] = a[i];
		}
	}
	free(sorted);
	return ;
}

int main()
{
	int array[100], n = 0, m = 0, next;
	printf("Enter items: ");
	while(scanf("%d", &next) == 1)
	{
		array[n++] = next;
	}
	
	unique_copy_unstable(array, n, array, &n);
	
	printf("Unique: ");
	for(int i = 0; i < n; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}