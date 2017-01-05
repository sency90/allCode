#include<iostream>
#include<stdio.h>
#pragma warning (disable:4996)

int search(int arr[], int x, int n)
{
for (int i = 0; i < n; i++)
if (arr[i] == x)
return i;
return -1;
}

  /*
//������ȸ�� ������ȸ�� �̿��ؼ� ������ȸ���
void printPostOrder(int in[], int pre[], int n)
{
//������ȸ�� ù��°���Ҵ� �׻� root, root�� �������ҿ��� ã�� ���ʰ� ������ ����Ʈ���� ã��
int root = search(in, pre[0], n);

// If left subtree is not empty, print left subtree
if (root != 0)
printPostOrder(in, pre + 1, root);

// If right subtree is not empty, print right subtree
if (root != n - 1)
printPostOrder(in + root + 1, pre + root + 1, n - root - 1);

// Print root
cout << pre[0] << " ";
}
  */

//������ ������ �̿��ؼ� ���� ����ϱ�
void printInOrder(int post[], int pre[], int n)
{
	int root = search(pre, pre[0], n);

	if (root != 0)
		printInOrder(pre, post-1 , root);
	if (root != n - 1)
		printInOrder(post+ 1 , pre+root+1, n - root - 1);
	printf("%d ", pre[0]);
	//cout << pre[0] << " ";
}


int main()
{
int i = 0;
int num = 0;
int pre[1000];
int post[1000];
//int in[100];

scanf("%d", num);

for (int i=0 ; i < num; i++)
{
	scanf("%d", &pre[i]);
}
for (int i = 0 ;i < num; i++)
{
	scanf("%d", &post[i]);
}
/*
//test
int in[] = { 4, 2, 5, 1, 6, 3,7 };
int pre[] = { 1, 2, 4, 5, 3, 6,7 };
int post[] ={4,5,2,6,7,3,1};
	int n = sizeof(in) / sizeof(in[0]);
cout << "Postorder traversal " << endl;
printPostOrder(in, pre, n);
cout << endl;
cout << "Inorder traversal" << endl;
*/
printInOrder(post, pre, num);
return 0;
}
