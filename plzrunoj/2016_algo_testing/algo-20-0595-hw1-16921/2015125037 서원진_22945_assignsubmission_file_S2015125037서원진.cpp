#include <stdio.h>

int preorder[1000];
int postorder[1000]; 
int inorder[1000]; 
int N;

void search(int *pre, int *post, int *in, int number_n) {
	int id;
	if (number_n <= 0) return;
	if (number_n == 1) {
		in[0] = pre[0];
		return;
	}
	for (id = 0; pre[1] != post[id]; id++); id += 1;
	in[id] = pre[0];
	search(pre + 1, post, in, id);
	search(pre + id + 1, post + id, in + id + 1, number_n - id - 1);
}

int main()
{
	int i;
	printf("노드 개수 입력 (1~1000):\n");
	scanf("%d", &N);
	printf("전위순회 순서 입력");
	for (i = 0; i < N; i++) scanf("%d", &preorder[i]);
	printf("후위순회 순서 입력");
	for (i = 0; i < N; i++) scanf("%d", &postorder[i]);
	for (i = 0; i < N; i++) inorder[i] = -1;
	search(preorder, postorder, inorder, N);
	printf("중위순회 결과");
	for (i = 0; i < N; i++) printf("%d ", inorder[i]);
	printf("\b\n");
	scanf("%d", &N);
	return 0;
}

