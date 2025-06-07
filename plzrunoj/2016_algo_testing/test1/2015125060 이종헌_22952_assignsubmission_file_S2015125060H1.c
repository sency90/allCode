#include <stdio.h>
#include <iostream>

using namespace std;

void inorder(int *x, int *y, int i) {
	if(x[i] != 0) {
		inorder(x, y, i * 2);
		for(int j = 1; j < 1000; j++) {
			if(y[j] == 0) {
				y[j] = x[i];
				break;
			}
		}
		inorder(x, y, i * 2 + 1);
	}
}

void solve(int *pre, int *post, int *result, int index, int num) {
	int a[1001] = {0, };
	int b[1001] = {0, };
	int c[1001] = {0, };
	int d[1001] = {0, };

	result[index] = pre[1];
	
	if(index <= num) {
		for(int j = 1; j <= num; j++) {
			if(pre[2] == post[j]) {
				copy(pre + 2, pre + (j + 2), a + 1);
				copy(post + 1, post + (j + 1), b + 1);
				solve(a, b, result, index * 2, num);
				copy(pre + (j + 2), pre + (num + 1), c + 1);
				copy(post + (j + 1), post + (num + 1), d + 1);
				solve(c, d, result, index * 2 + 1, num);
				break;
			}
		}
	} else {
		return;
	}
}

int main() {
	int input[1001] = {0, };
	int in[1001] = {0, };
	int pre[1001] = {0, };
	int post[1001] = {0, };
	int num;

	scanf("%i", &num);
	for(int i = 1; i <= num; i++) {
		scanf("%i", &pre[i]);
	}

	for(int i = 1; i <= num; i++) {
		scanf("%i", &post[i]);
	}

	solve(pre, post, input, 1, num);
	inorder(input, in, 1);

	for(int i = 1; i <= num; i++) {
		printf("%i ", in[i]);
	} printf("\n");

	return 0;
}