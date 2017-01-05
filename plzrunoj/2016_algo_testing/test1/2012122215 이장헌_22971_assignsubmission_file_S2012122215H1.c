#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *left;
	struct Node *right;
	int number;

};

struct Node* newNode(int data)
{
	struct Node* temp = (struct Node *) malloc(sizeof(struct Node));

	temp->number = data;
	temp->left = temp->right = NULL;

	return temp;
}

struct Node* TreeUtil(int pre[], int post[], int* preIDX,
	int l, int h, int sz)
{
	if (*preIDX >= sz || l > h)
		return NULL;

	struct Node* root = newNode(pre[*preIDX]);
	++*preIDX;

	if (l == h)
		return root;

	int i;
	for (i = l; i <= h; ++i)
		if (pre[*preIDX] == post[i])
			break;

	if (i <= h)
	{
		root->left = TreeUtil(pre, post, preIDX, l, i, sz);
		root->right = TreeUtil(pre, post, preIDX, i + 1, h, sz);
	}

	return root;
}

struct Node *Tree(int pre[], int post[], int sz)
{
	int preIDX = 0;
	return TreeUtil(pre, post, &preIDX, 0, sz - 1, sz);
}

void printInorder(struct Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->number);
	printInorder(node->right);
}

int main()
{
	struct Node* temp = (struct Node *) malloc(sizeof(struct Node));
	int num = 0;
	int* preInter;
	int* postInter;
	scanf_s("%d", &num);
	preInter = (int*)malloc(sizeof(int)*num); ;
	postInter = (int*)malloc(sizeof(int)*num); ;
	for (int i = 0; i < num; i++) {
		scanf_s("%d", &preInter[i]);
	}
	for (int i = 0; i < num; i++) {
		scanf_s("%d", &postInter[i]);
	}
	int size = num;

	struct Node *root = Tree(preInter, postInter, size);

	printInorder(root);

	return 0;
}
