#include <iostream>
#include <vector>

using namespace std;

int n1, n2;
bool c1[200000], c2[200000];
int con[200000];
vector< vector<bool> > r1, r2;

void gropu(int g, int u)
{
	con[u] = g;
	for(int i = 0; i < n1; ++i)
	{
		if(r1[u][i])
		{
			if()
		}
	}
}

int main()
{
	//freopen("test", "r", stdin);
	//freopen("", "w", stdout);

	cin >> n;
    r1 = vector< vector<bool> >(n1);
    r2 = vector< vector<bool> >(n1);
	for(int i = 0; i < n; ++i)
	{
	    r1[i] = vector<bool>(n1);
	    r2[i] = vector<bool>(n1);
		cin >> c1[i];
		con[i] = -1;
	}

	for(int i = 0; i < nt1 - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		r[u-1][v-1] = 1;
		r[v-1][u-1] = 1;
	}

	for(int i = 0; i < n; ++i)
	{
		if(con[i] == -1)
		{
			c2[m] = c1[i];
			group(m, i);
			m++;
		}
	}

	int p[] = {0, 0};
	for(int i = 0; i < m; ++i)
	{
		p[g[i]]++;
	}

	if(p[0] > p[1]) cout << p[1];
	else cout << p[0];

	return 0;
}