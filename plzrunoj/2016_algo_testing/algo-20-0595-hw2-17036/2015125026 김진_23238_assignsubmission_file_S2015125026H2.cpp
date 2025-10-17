#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;
	int arr[1000];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n-1);
	
	int max = 0;
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] <= n - i) {
			num = arr[i];
		}
		if (max < num) {
			max = num;
		}
	}
	cout << max;
	return 0;
}