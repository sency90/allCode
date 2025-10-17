#include<iostream>
using namespace std;

int main()
{
	int n;
	int data[10000] = { 0 };
	int i;
	int x;
	int count = 0;
	int max = 0;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x;
		data[x]++;
	}
	for (i = 0; i < 10000; i++)
	{
		if (n - count >= i) max = i;
		else break;
		count += data[i];
	}
	cout << max;
}