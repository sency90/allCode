#include <cstdio>
using namespace std;

void inorder(int* pre, int* post) {
	int root = pre[0];
	int j;
	for (j = 0; pre[1] != post[j]; j++);
	if (j) {
		inorder(&pre[1], &post[0]);
		printf_s("%i ", root);
		inorder(&pre[j + 2], &post[j+1]);
	}
	else {
		printf_s("%i %i %i ", post[0], root, pre[2]);
		return;
	}
}

int main() {
	int n;
	scanf_s("%i", &n);

	int* pre = new int[n];
	int* post = new int[n];
	int* in = new int[n] {0};

	for (int i = 0; i < n; i++) scanf_s("%i", &pre[i]);
	for (int i = 0; i < n; i++) scanf_s("%i", &post[i]);

	inorder(pre, post);
	printf_s("\n");

	return 0;
}