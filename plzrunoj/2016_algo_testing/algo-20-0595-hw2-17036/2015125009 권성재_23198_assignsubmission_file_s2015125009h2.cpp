#include <stdio.h>
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int n;
	int cnt;
	int ret = -1;

	//입력을 받음
	scanf("%d", &n);
	int* in_arr = new int[n];
	int* cnt_arr = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &in_arr[i]);
	

	for (int i = 0; i < n; i++) {
		cnt_arr[i] = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (in_arr[i] <= in_arr[j]) {
					cnt_arr[i]++;
				}
			}
			else {
				cnt_arr[i]++;
			}
		}
		
		if (in_arr[i] <= cnt_arr[i]) {
			if (ret < in_arr[i]) {
				ret = in_arr[i];
			}
		}
	}


	printf("%d", ret);

	return 0;
}