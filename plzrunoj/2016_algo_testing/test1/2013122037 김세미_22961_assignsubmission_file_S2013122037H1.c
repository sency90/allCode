//
//  main.c
//  alll
//
//  Created by KIMSEMI on 2016. 12. 5..
//  Copyright © 2016년 KIMSEMI. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

//전역변수
int pre[1000];       //전위순회 배열
int post[1000];      //후위순회 배열
int n;              //노드갯수
int preI = 0;       //pre배열 index, pre배열 원소 순으로 트리 생성

//트리 노드 정의
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

//노드 생성 & 초기화
struct node* newNode (int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
    
    temp->data = data;
    temp->left = temp->right = NULL;
    
    return temp;
}

struct node* makeOriginTree (int start, int end)
{
    // index가 배열크기를 초과하거나 post배열 탐색의 시작점이 끝점보다 클 경우 return null
    if (preI >= n || start > end)
        return NULL;
    
    //pre 배열의 현재 원소로 노드 생성
    struct node* root = newNode ( pre[preI] );
    ++preI;
    
    // 시작점과 끝점이 같을 경우, preI가 가르키는 원소가 없을 경우
    // 해당 노드는 자식노드가 없으므로 return root(현재 노드)
    if (start == end || preI == n)
        return root;
    
    // 다음으로 찾을 pre배열의 node의 post배열에서의 위치 파악
    for (int i = start; i <= end; ++i){
        if (pre[preI] == post[i])
        {
            root->left = makeOriginTree (start, i);     //i보다 왼쪽에 있는 원소 중 노드의 왼쪽 자식 찾기
            root->right = makeOriginTree (i + 1, end);  //i보다 오른쪽에 있는 원소 중 노드의 오른쪽 자식 찾기
            break;
        }
    }
    
    //왼쪽 자식, 오른쪽 자식 다 찾은 후 return root
    return root;
}

//완성된 트리 중위 순회로 출력
void inorder (struct node* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main ()
{
    //변수 입력
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&pre[i]);
    }
    
    for(int i = 0; i < n; i++){
        scanf("%d",&post[i]);
    }
    
    struct node *root = makeOriginTree(0,n-1);      //원래 트리 만들기
    inorder(root);
    
    return 0;
}
