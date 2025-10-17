//C언어로 전위 후위를 입력하여 중위를 결과로 출력하기(Visual C++ 2010 Express 관리자 툴 사용)

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//노드
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 
//새노드생성
struct node* newNode (int data)
{
    struct node *temp = (struct node*) malloc(sizeof(struct node));
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}
 
//재귀함수
struct node* constructTreeUtil (int pre[], int post[], int* preIndex,
                                int l, int h, int size)
{
    
    if (*preIndex >= size || l > h)
        return NULL;

    //전위 첫노드는 root
    struct node* root = newNode ( pre[*preIndex] );
    ++*preIndex;
 
    // 같으면 리턴
    if (l == h)
        return root;
 
    // 후위에서 다음 전위원소를 찾는다
    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;
 
    //왼쪽 오른쪽 하위트리로 나눈다 
    if (i <= h)
    {
        root->left = constructTreeUtil (pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil (pre, post, preIndex, i + 1, h, size);
    }
 
    return root;
}
 
//주어진 전위와 후위로 완전이진트리를 구성
struct node *constructTree (int pre[], int post[], int size)
{
    int preIndex = 0;
    return constructTreeUtil (pre, post, &preIndex, 0, size - 1, size);
}
 
//중위출력
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
	
	//n값 추가, 배열생성 및 추가
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