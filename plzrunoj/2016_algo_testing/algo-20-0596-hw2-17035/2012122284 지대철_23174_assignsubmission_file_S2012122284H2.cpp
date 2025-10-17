#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int Number[1000];
	int count;
	int Max = 0;
	cin >> count;

	for (int i = 0; i < count; i++) cin >> Number[i];
	sort(Number, Number + count);
	for (int i = 0; i < count; i++) {
		if (Number[i] > count - i) break;
		Max = Number[i];
	}
	if (Max == 0) cout << "error";
	else cout << Max;
	system("pause");
	return 0;
}