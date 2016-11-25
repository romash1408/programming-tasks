#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[100000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        int next;
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    long max = 0;
    int m = min(n, k);
    for(int i = n - 1; i >= n - m ; --i){
        max += arr[i];
    }
    
    cout << max;
    
	return 0;
}