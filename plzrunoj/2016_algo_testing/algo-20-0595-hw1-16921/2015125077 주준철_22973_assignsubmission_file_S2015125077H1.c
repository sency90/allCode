#include <stdio.h>
#include <stdlib.h>

// ���� ������ȸ����� �̿��� ������ȸ ����� ����
//������ȸ���� pre[0]�� ��Ʈ�̰� pre[1]��  post���� ã�Ƴ�
//for(i++)���� i��ŭ�� pre[1]~pre[i]��ŭ ���� �������� ��������
//����Լ�


struct node
{
	int data;
	struct node *left;
	struct node *right;
};

// ������
struct node* newNode(int data)
{
	struct node* temp = (struct node *) malloc(sizeof(struct node));

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

struct node* constructTreeUtil(int pre[], int post[], int* preIndex, int l, int h, int size)
{
	if (*preIndex >= size || l > h)
		return NULL;

	//������
	struct node* root = newNode(pre[*preIndex]);
	++*preIndex;

	if (l == h)
		return root;

	// ����ã��
	int i;
	for (i = l; i <= h; ++i)
		if (pre[*preIndex] == post[i])
			break;

	//Ʈ��
	if (i <= h)
	{
		root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
		root->right = constructTreeUtil(pre, post, preIndex, i + 1, h, size);
	}

	return root;
}


struct node *constructTree(int pre[], int post[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, post, &preIndex, 0, size - 1, size);
}

//������ȸ
void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

int main()
{
	int number;
	scanf_s("%d", &number);


	int pre[1000];
	int post[1000];
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &pre[i]);
	}
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &post[i]);
	}

	struct node *root = constructTree(pre, post, number);

	printInorder(root);

	return 0;
}
