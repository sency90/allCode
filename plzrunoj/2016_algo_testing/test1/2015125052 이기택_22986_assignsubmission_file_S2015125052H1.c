#include<stdio.h>

int count = 0;
int pre_order[1000];
int post_order[100];
int in_order[1000] = { 0 };

void make_inorder(int *pre_order,int *post_order,int count, int *in_order) {
	int i;
	if (count < 1) {
		return;
	}
	if (count == 1) {
		in_order[0] = pre_order[0];
		return;
	}
	for (i = 0; pre_order[1] != post_order[i]; i++) {
	}
	i += 1;
	in_order[i] = pre_order[0];
	
	make_inorder(pre_order+1,post_order,i,in_order);
	make_inorder(pre_order + i + 1, post_order + i, count - i - 1, in_order + i + 1);
}

int main() {
	scanf("%d",&count);
	for (int i = 0; i < count; i++) {
		scanf("%d", &pre_order[i]);
	}
	for (int i = 0; i < count; i++) {
		scanf("%d", &post_order[i]);
	}

	make_inorder(pre_order, post_order, count, in_order);

	for (int i = 0; i < count; i++) {
		printf("%2d", in_order[i]);
	}

	return 0;
}