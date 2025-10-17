#include <iostream>
#include <algorithm>

using namespace std;

int Number[1000];
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> Number[i];
	sort(Number, Number + n);
	int Max;
	for (int i = 0; i < n; i++)
	{
		if (Number[i] > n - i) break;
		else Max = Number[i];
	}
	cout << Max;
}