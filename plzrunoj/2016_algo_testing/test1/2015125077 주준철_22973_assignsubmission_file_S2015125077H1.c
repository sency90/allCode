#include <stdio.h>
#include <stdlib.h>

// 전위 후위순회결과를 이용해 중위순회 결과값 내기
//전위순회에서 pre[0]은 루트이고 pre[1]을  post에서 찾아냄
//for(i++)에서 i만큼이 pre[1]~pre[i]만큼 왼쪽 나머지가 오른쪽임
//재귀함수


struct node
{
	int data;
	struct node *left;
	struct node *right;
};

// 노드생성
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

	//노드생성
	struct node* root = newNode(pre[*preIndex]);
	++*preIndex;

	if (l == h)
		return root;

	// 왼쪽찾기
	int i;
	for (i = l; i <= h; ++i)
		if (pre[*preIndex] == post[i])
			break;

	//트리
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

//중위순회
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
