//C���� ���� ������ �Է��Ͽ� ������ ����� ����ϱ�(Visual C++ 2010 Express ������ �� ���)

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//���
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 
//��������
struct node* newNode (int data)
{
    struct node *temp = (struct node*) malloc(sizeof(struct node));
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}
 
//����Լ�
struct node* constructTreeUtil (int pre[], int post[], int* preIndex,
                                int l, int h, int size)
{
    
    if (*preIndex >= size || l > h)
        return NULL;

    //���� ù���� root
    struct node* root = newNode ( pre[*preIndex] );
    ++*preIndex;
 
    // ������ ����
    if (l == h)
        return root;
 
    // �������� ���� �������Ҹ� ã�´�
    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;
 
    //���� ������ ����Ʈ���� ������ 
    if (i <= h)
    {
        root->left = constructTreeUtil (pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil (pre, post, preIndex, i + 1, h, size);
    }
 
    return root;
}
 
//�־��� ������ ������ ��������Ʈ���� ����
struct node *constructTree (int pre[], int post[], int size)
{
    int preIndex = 0;
    return constructTreeUtil (pre, post, &preIndex, 0, size - 1, size);
}
 
//�������
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
 

int main ()
{
	int n;
	int i;
	int *pre;
	int *post;
	
	//n�� �߰�, �迭���� �� �߰�
	printf("Please Input n value: \n");
	scanf("%d",&n);

	pre = (int*)malloc(sizeof(int)*n);
	post = (int*)malloc(sizeof(int)*n);


	printf("Please Input pre value: \n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}fflush(stdin);
	printf("Please Input post value: \n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&post[i]);
	}fflush(stdin);
    
 
    struct node *root = constructTree(pre, post, n);
 
    printf("Inorder traversal: \n");
    printInorder(root);
    printf("\n");
    return 0;
}