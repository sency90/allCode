#include <stdio.h>

void search(int *pre, int *post, int *in, int number_of_node) {
	int idx;
	if (number_of_node <= 0) return;
	if (number_of_node == 1) {
		in[0] = pre[0];
		return;
	}
	for (idx = 0; pre[1] != post[idx]; idx++); idx += 1;
	in[idx] = pre[0];
	search(pre + 1, post, in, idx);
	search(pre + idx + 1, post + idx, in + idx + 1, number_of_node - idx - 1);
}
int main(void)
{
	int preorder[1000]; // M-L-R
	int postorder[1000]; // L-R-M
	int inorder[1000]; // L-M-R
	int N;
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &preorder[i]);
	for (i = 0; i < N; i++) scanf("%d", &postorder[i]);
	for (i = 0; i < N; i++) inorder[i] = -1;
	search(preorder, postorder, inorder, N);
	for (i = 0; i < N; i++) printf("%d ", inorder[i]);
	printf("\b\n");
	return 0;
}