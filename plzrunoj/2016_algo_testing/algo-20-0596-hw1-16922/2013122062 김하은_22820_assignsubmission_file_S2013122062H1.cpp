
#include <stdio.h>
#include <stdlib.h>
 
int error_flag = 0;

//트리 노드 구조체
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 
//새 노드 생성
struct node* newNode (int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
 
    temp->data = data;
    temp->left = NULL;
   temp->right =NULL;
 
    return temp;
}


//두 순회 결과를 통해 트리를 만들어 주기 위한 함수

struct node* make_Tree(int *pre_arr, int *post_arr, int* pre_index,int start_point, int end_point, int node_num){   

   int i;
   
    
     //시작 인덱스가 종료인덱스 보다 큰경우는 return.
    if (*pre_index >= node_num || start_point > end_point)
        return NULL;
 
    
    struct node* root = newNode ( pre_arr[*pre_index] );
    *pre_index=*pre_index+1;
 
   //두 인덱스가 같은 경우에는 루트로 반환
    if (start_point == end_point){
      return root;
   }
   
    //전위순회와 후위순회에서 Unique한 트리가 아닐 경우 Break해줌 
    for (i = start_point; i <= end_point; ++i)
        if (pre_arr[*pre_index] == post_arr[i])
            break;
 
    
    //재귀적으로 트리를 만들어줌
    if (i <= end_point)
    {
        root->left = make_Tree(pre_arr, post_arr, pre_index, start_point, i, node_num);
        root->right = make_Tree(pre_arr, post_arr, pre_index, i + 1, end_point, node_num);
    }
 
    return root;
}
 


// 중위순회 출력
void Inorder (struct node* node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}


int main(){

   int b;
   int node_num =0; //노드 갯수
   int i;
   //전위 순회 값 저장될 동적 배열할당
   int *pre_arr; 
   //후위 순회 값 저장될 동적 배열할당
   int *post_arr;
   int pre_index = 0;
   struct node *root; 
  

       //트리의 노드 수 입력 
	  printf("노드수를 입력하세요 : ");
      scanf("%d", &node_num);

      //노드 수 만큼 동적으로 할당을 받아줌
      pre_arr = (int*)malloc(sizeof(int*)*node_num); 
      post_arr = (int*)malloc(sizeof(int*)*node_num);

   
      //전위순회 노드 순서 입력
         for(i=0; i< node_num; i++){

            scanf("%d", &pre_arr[i]);
         }

      //후위순회 노드 순서 입력
         for(i=0; i< node_num; i++){

            scanf("%d", &post_arr[i]);
         }
   
   //전위순회의 첫번째 노드는 트리의 루트이다.
    //노드의 수는 최대 인덱스의 -1까지이므로 end_point를 노드개수에서 1뺀 값으로 설정       
 
    root = make_Tree(pre_arr, post_arr, &pre_index, 0, node_num - 1, node_num);
 
    printf("중위순회 결과 \n");
   if(error_flag ==0){
    Inorder(root);
   }
   else{
      printf("unique한 tree가 아닙니다\n");
   }
      free(pre_arr);  //할당받은 동적배열 메모리 해제
      free(post_arr);   
  
}

