#include<iostream>

using namespace std;

int main()
{
	int n, x, num=0, ans=0;
	int arr[10000] = { 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		arr[x]++;
	}

	for (int i = 0; i < 10000; i++)
	{
		if (n - num >= i) {
			ans = i;
		}
		num += arr[i];
	}

	cout << ans;

	return 0;
}