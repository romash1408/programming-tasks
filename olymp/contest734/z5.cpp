#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool c[200000], g[200000];
int ng[200000];

int main()
{
	//freopen("test", "r", stdin);
	//freopen("", "w", stdout);

	cin >> n;
    vector< vector<bool> > r(n);
	for(int i = 0; i < n; ++i)
	{
	    r[i] = vector<bool>(n);
		cin >> c[i];
		ng[i] = -1;
	}
	for(int i = 0; i < n-1; ++i)
	{
		int u, v;
		cin >> u >> v;
		r[u-1][v-1] = 1;
		r[v-1][u-1] = 1;
	}
	for(int i = 0; i < n; ++i)
	{
		if(ng[i] == -1)
		{
			//cout << i << " to group " << m << endl;
			ng[i] = m;
			g[m] = c[i];
			++m;
		}
		for(int j = i + 1; j < n; ++j)
		{
			//cout << "\t("<< i << ", " << j << ") = " << r[i][j] << endl;
			if(!r[i][j] || c[i] != c[j]) continue;
			//cout << '\t' << j << " to group " << ng[i] << endl;
			ng[j] = ng[i];
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