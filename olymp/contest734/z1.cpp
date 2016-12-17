#include <iostream>

using namespace std;

int main()
{
	//freopen("test", "r", stdin);
	//freopen("", "w", stdout);

	int n, w = 0;

	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		char c;
		cin >> c;
		w += (c == 'A') * 2 - 1;
	}

	if(w == 0) cout << "Friendship";
	else if(w > 0) cout << "Anton";
	else cout << "Danik";

	return 0;
}