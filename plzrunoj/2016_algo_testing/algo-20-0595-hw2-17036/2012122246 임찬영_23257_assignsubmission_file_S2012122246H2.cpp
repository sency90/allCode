#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	int a[1001];
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a+1, a + n+1);

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= n - i + 1 ) {
			answer = n - i +1;
			break;
		}
	}
	printf("%d", answer);

	return 0;
}