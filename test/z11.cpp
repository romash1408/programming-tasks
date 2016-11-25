#include <stdio.h>
#include <set>
#include <time.h>

int main() {
	clock_t t1 = clock(), t2, t3, t4 = 0, t5 = 0;
	t2 = clock();
	
	int n, m;
	std::set<int> p;
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		int add;
		scanf("%d", &add);
		p.insert(add);
	}
	m = p.size();
	
	t2 = clock() - t2;
	t3 = clock();
	
	int ans = n, in = 0, max;
	std::set<int>::const_iterator it = p.begin(), jt = p.begin();
	
	for(; it != p.end(); ++it)
	{
		max = *it + n;
		while(jt != p.end() && *jt < max) 
		{
			++in;
			++jt;
		}
		if(n - in < ans) ans = n - in;
		if(in > 0)
		{
			--in;
		}
		else
		{
			++jt;
		}
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