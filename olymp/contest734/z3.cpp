#include <iostream>

using namespace std;

int main()
{
	//freopen("test", "r", stdin);
	//freopen("", "w", stdout);

	int n, M, K, m, k, x, s, a[100000], b[100000], c[100000], d[100000];

	cin >> n >> M >> K >> x >> s;

	for(int i = 0; i < M; ++i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < M; ++i)
	{
		cin >> b[m];
		a[m] = a[i];
		if(b[m] <= s) ++m;
	}


	for(int i = 0; i < K; ++i)
	{
		cin >> c[i];
	}
	for(int i = 0; i < K; ++i)
	{
		cin >> d[k];
		if(b[k] <= s) ++k;
		else break;
	}

	int min = x * n;
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < k; ++j)
		{
			if(d[j] > s - b[i]) break;
			int time = a[i] * (n - c[j]);
			if(time < min) min = time;
		}
		int time = a[i] * n;
		if(time < min) min = time;
	}
	for(int j = 0; j < k; ++j)
	{
		int time = x * (n - c[j]);
		if(time < min) min = time;
	}

	cout << min;

	return 0;
}