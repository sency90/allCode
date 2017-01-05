#include <stdio.h>
#include <stdlib.h>

void inorder(int *preorder, int *postorder, int n);

int main() {
	int n;
	int *preorder;
	int *postorder;

	scanf("%d", &n);

	if (n < 1 || n > 1000)
	{
		printf("range error!\n");
		exit(0);
	}

	preorder = new int[n];
	postorder = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &preorder[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &postorder[i]);
	}

	inorder(preorder, postorder, n);
	printf("\n");

	delete[] preorder;
	delete[] postorder;

	return 0;
}


void inorder(int *preorder, int *postorder, int n) {

	if (n >= 1 && n <= 3)
	{
		switch (n)
		{
		case 1:
			printf("%d ", preorder[0]);
			break;

		case 2:
			printf("%d %d ", preorder[1], preorder[0]);
			break;

		case 3:
			printf("%d %d %d ", preorder[1], preorder[0], preorder[2]);
			break;
		default:
			break;
		}
	}

	else
	{
		int Root = postorder[n - 1];
		int right = postorder[n - 2];
		int point;
		int *preLeftChild;
		int *preRightChild;
		int pre_left, pre_right, post_left, post_right;
		int *postLeftChild;
		int *postRightChild;

		for (int i = 0; i< n; i++)
		{
			if (preorder[i] == right)
				point = i;
		}

		pre_left = point - 1;
		pre_right = n - point;
		post_left = point;
		post_right = n - (point + 1);

		preLeftChild = new int[pre_left];
		preRightChild = new int[pre_right];
		postLeftChild = new int[post_left];
		postRightChild = new int[post_right];

		for (int i = 1; i < n + 1; i++)
		{
			if (i < point) preLeftChild[i - 1] = preorder[i];
			else           preRightChild[i - point] = preorder[i];
		}

		for (int i = 0; i < n - 1; i++)
		{
			if (i < point - 1) postLeftChild[i] = postorder[i];
			else               postRightChild[i + 1 - point] = postorder[i];
		}


		inorder(preLeftChild, postLeftChild, pre_left);

		printf("%d ", Root);

		inorder(preRightChild, postRightChild, pre_right);
	}

}