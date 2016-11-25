#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
	if(adding->val == tree->val) return ;
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


int main() {
	clock_t t1 = clock(), t2, t3, t4 = 0, t5 = 0;
	t2 = clock();
	
	int n, m = 0, p[100000];
	struct unit tree[100000];
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &tree[i].val);
		tree[i].left = tree[i].right = 0;
		if(i > 0) add(tree, tree + i);
	}
	m = ascent(tree, p) - p;
	
	t2 = clock() - t2;
	t3 = clock();
	
	int ans = n, in = 0, max;	
	
	for(int i = 0; i < ans; ++i)
	{
		max = p[i] + n;
		while(i + in < m && p[i + in] < max) ++in;
		if(n - in < ans) ans = n - in;
		if(in > 0) --in;
	}
	
	t3 = clock() - t3;
	t1 = clock() - t1;
	
	printf(
		"%d at time %f s (reading %f s, counting %f s)\n",
		ans,
		(float)t1 / CLOCKS_PER_SEC,
		(float)t2 / CLOCKS_PER_SEC,
		(float)t3 / CLOCKS_PER_SEC
	);
	return 0;
}