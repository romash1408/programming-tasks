#include <iostream>

using namespace std;

struct fig
{
	char t;
	long x;
	long y;
};

int main()
{
	//freopen("test", "r", stdin);
	//freopen("", "w", stdout);

	const long _INT_MAX = 2000000001;
	long n, x, y, d[8] = {-_INT_MAX, -_INT_MAX, _INT_MAX, -_INT_MAX, _INT_MAX, -_INT_MAX, _INT_MAX, _INT_MAX};
	cin >> n >> x >> y;

	struct fig f[500000];
	for(long i = 0; i < n; i++)
	{
		cin >> f[i].t >> f[i].x >> f[i].y;
		f[i].x -= x;
		f[i].y -= y;
		switch(f[i].t)
		{
		case 'B':
			if(f[i].x == 0)
			{
				if(f[i].y < 0 && d[1] < f[i].y) d[1] = f[i].y;
				else if(f[i].y > 0 && d[6] > f[i].y) d[6] = f[i].y;
			}
			else if(f[i].y == 0)
			{
				if(f[i].x < 0 && d[3] < f[i].x) d[3] = f[i].x;
				else if(f[i].x > 0 && d[4] > f[i].x) d[4] = f[i].x;
			}
			break;
		case 'R':
			if(f[i].x == f[i].y )
			{
				if(f[i].x < 0 && d[0] < f[i].x) d[0] = f[i].x;
				else if(f[i].x > 0 && d[7] > f[i].x) d[7] = f[i].x;
			}
			else if(f[i].x == -f[i].y)
			{
				if(f[i].x < 0 && d[5] < f[i].x) d[5] = f[i].x;
				else if(f[i].x > 0 && d[2] > f[i].x) d[2] = f[i].x;
			}
			break;
		}
	}

	bool shah = false;
	for(long i = 0; i < n; ++i)
	{
		if(f[i].t == 'B' || f[i].t == 'Q')
		{
			if(
				(f[i].x == f[i].y && f[i].x > d[0] && f[i].x < d[7])
					||
				(f[i].x == -f[i].y && f[i].x > d[5] && f[i].x < d[2])
			)
			{
				shah = true;
				break;
			}
		}
		if(f[i].t == 'R' || f[i].t == 'Q')
		{
			if(
				(f[i].x == 0 && f[i].y > d[1] && f[i].y < d[6])
					||
				(f[i].y == 0 && f[i].x > d[3] && f[i].x < d[4])
			)
			{
				shah = true;
				break;
			}
		}
	}

	cout << (shah ? "YES" : "NO");

	return 0;
}