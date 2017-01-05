#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//다음과 같이 전위 후위가 주어졌을 때
//전위 1 2    |case.1    1    |case.2    1    |     
//후위 2 1    |        2      |            2  |
//위와 같이 2가지 경우가 생기는데 무조건 case1의 경우만 있다고 가정하고 문제를 풀었다.

using namespace std;

int pre[1000];
int post[1000];
int in[1000];

void want_inorder(int pre_start, int pre_end, int post_start, int post_end, int in_start) {
	int cnt = 0;

	if (pre_start == pre_end) {
		in[in_start] = pre[pre_start];
		return;
	}

	for (int i = post_start; i <= post_end; i++) {
		if (post[i] == pre[pre_start + 1]) {
			cnt = i - post_start + 1;
			break;
		}
	}
	in[in_start + cnt] = pre[pre_start];

	if (pre_start + 1 <= pre_start + cnt)
		want_inorder(pre_start + 1, pre_start + cnt, post_start, post_start + cnt - 1, in_start);
	if (pre_start + 1 + cnt <= pre_end)
		want_inorder(pre_start + 1 + cnt, pre_end, post_start + cnt, post_end - 1, in_start + cnt + 1);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}

	want_inorder(0, n - 1, 0, n - 1, 0);

	for (int i = 0; i < n; i++) {
		printf("%d ", in[i]);
	}
	return 0;
}

