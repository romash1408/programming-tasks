#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &m, &n);
	
	int sums[10001], s = 1, max = 0;
	sums[0] = 0;
	for(; n >= 0; n--)
	{
		int cur;
		scanf("%d", &cur);
		if(cur > m) continue ;
		for(int j = s-1; j >= 0; --j)
		{
			int sum = sums[j] + cur;
			if(sum <= m)
			{
				int l = 0, r = s;
				for(int i; r - l > 1; i = l + (r-l)/2)
				{
					if(sums[i] == sum) 
					{
						l = i;
						break;
					}
					if(sums[i] > sum) r = i;
					else l = i + 1;
				}
				if(l == s || sums[l] != sum)
				{
					if(sum > max) max = sum;
					if(max == m) break ;
					l += (l != s && sums[l] < sum);
					for(int i = s; i > l; --i)
					{
						sums[i] = sums[i-1];
					}
					sums[l] = sum;
					s++;
				}
			}
		}
		if(max == m) break ;
	}
	
	printf("%d", max);
	return 0;
}