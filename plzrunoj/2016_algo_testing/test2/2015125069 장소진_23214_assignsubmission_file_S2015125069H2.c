#include <iostream>
using namespace std;
int main() {
	int cnt,j = 0, temp_1 = 0,a[50];
	cin >> cnt;
	for (int i = 0; i < cnt; i++) cin >> a[i];
	while (j < cnt) {
		int k = 0, temp = 0;
		while (k < cnt) {
			if (a[k] >= a[j]) temp++;
			k++;
		}
		if (temp >= a[j]) {
			if (temp_1 - a[j] < 0) temp_1 = a[j];
		}
		j++;
	}
	cout << temp_1 << endl;
	return 0;
}