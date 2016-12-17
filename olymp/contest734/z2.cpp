#include <iostream>

using namespace std;

int min(int a, int b)
{
	if(a <= b) return a;
	return b;
}

int main()
{
	//freopen("test", "r", stdin);
	//freopen("", "w", stdout);

	int k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;

	int k256 = min(k2, min(k5, k6));
	k2 -= k256;
	int k32 = min(k3, k2);
	cout << (k256 * 256 + k32 * 32);

	return 0;
}