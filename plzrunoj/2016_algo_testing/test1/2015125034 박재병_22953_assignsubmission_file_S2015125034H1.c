#include <stdio.h>

int preOrder[10000];
int postOrder[10000];
int inOrder[10000];
int N;

void search(int* pre, int* post, int* in, int Size) {
	int pos;
	if (Size <= 0) {
		return;
	}
	if (Size == 1) {
		in[0] = pre[0];
		return;
	}
	for (pos = 0; pre[1] != post[pos]; pos++);
	pos++;
	in[pos] = pre[0];
	search(pre + 1, post, in, pos);
	search(pre + pos + 1, post + pos, in + pos + 1, Size - pos - 1);
}

int main() {
	int i = 0;
	scanf_s("%d", &N);
	for (i = 0; i < N; i++) {
		scanf_s("%d", &preOrder[i]);
	}
	for (i = 0; i < N; i++) {
		scanf_s("%d", &postOrder[i]);
	}
	for (i = 0; i < N; i++) {
		inOrder[i] = 0;
	}
	search(preOrder, postOrder, inOrder, N);
	for (i = 0; i < N; i++) {
		printf("%d ", inOrder[i]);
	} 
	return 0;
}