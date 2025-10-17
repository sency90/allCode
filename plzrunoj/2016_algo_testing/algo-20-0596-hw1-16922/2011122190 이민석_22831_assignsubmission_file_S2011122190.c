#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode (int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
    
    temp->data = data;
    temp->left = temp->right = NULL;
    
    return temp;
}

struct node* constructTreeUtil (int pre[], int post[], int* preIndex,
                                int l, int h, int size)
{
    if (*preIndex >= size || l > h)
        return NULL;
    
    struct node* root = newNode ( pre[*preIndex] );
    ++*preIndex;
    
    if (l == h)
        return root;
    
    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;
    
    if (i <= h)
    {
        root->left = constructTreeUtil (pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil (pre, post, preIndex, i + 1, h, size);
    }
    
    return root;
}

struct node *constructTree (int pre[], int post[], int size)
{
    int preIndex = 0;
    return constructTreeUtil (pre, post, &preIndex, 0, size - 1, size);
}

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
    
    scanf("%d", &n);
    
    int pre[1000];
    int post[1000];
    
    int i = 0;
    for (i=0; i<n; i++) {
        scanf("%d", &pre[i]);
    }
    
    for (i=0; i<n; i++) {
        scanf("%d", &post[i]);
    }
    
    struct node *root = constructTree(pre, post, n);
    
    printInorder(root);
    
    return 0;
}