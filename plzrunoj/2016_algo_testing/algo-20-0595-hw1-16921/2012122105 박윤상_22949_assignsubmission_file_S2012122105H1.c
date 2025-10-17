#include <stdio.h> 

static int Inorder_node[1000];
int k = 0;
int m = 0;

void Inorder(int* Pre, int* Post, int Nnum) {
	if (*Pre == 0) {
		return;
	}
	int post_left[1000] = { NULL };
	int post_right[1000] = { NULL };
	int pre_left[1000] = { NULL };
	int pre_right[1000] = { NULL };
	
	int i, j;
	int temp;

	temp = Pre[0];
	
	if (Nnum == 1) {           
		Inorder_node[m] = Pre[0];
		m++;
		return;
	}

	
	for (i= 0; i < Nnum; i++) {
		if (Pre[1] == Post[i]) {
			for (j = 0; j < i + 1; j++) {
				post_left[k]= Post[j];
				k++;
			}
			k = 0;
			for (j = i + 1; j < Nnum - 1; j++) {
				post_right[k] = Post[j];
				k++;
			}
			k = 0;
			for (j = 1; j < i + 2; j++) {
				pre_left[k] = Pre[j];
				k++;
			}
			k = 0;
			for (j = i + 2; j < Nnum; j++) {
				pre_right[k] = Pre[j];
				k++;
			}
			k = 0;
			Inorder(pre_left, post_left, i+1);
			Inorder_node[m] = temp;
			m++;
			Inorder(pre_right, post_right, Nnum - 2 - i);
		}
	}
}
int main(void)
{
	int A[1000];
	int B[1000];
	int num;
	int i;

	scanf("%d", &num);
	if (num > 1000 || num < 0) {

		printf("범위 초과\n");
		return 0;
	}
	printf("\n");
	for (i = 0; i < num; i++) {
		scanf("%d", &A[i]);
	}
	printf("\n");
	for (i = 0; i < num; i++) {
		scanf("%d", &B[i]);
	}
	printf("\n\n");
	Inorder(A, B, num);
	for (i = 0; i < num; i++) {
		printf("%d ", Inorder_node[i]);
	}
	printf("\n");

	return 0;
}
