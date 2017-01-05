
#include <stdio.h>
#include <stdlib.h>
 
int error_flag = 0;

//Ʈ�� ��� ����ü
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 
//�� ��� ����
struct node* newNode (int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
 
    temp->data = data;
    temp->left = NULL;
   temp->right =NULL;
 
    return temp;
}


//�� ��ȸ ����� ���� Ʈ���� ����� �ֱ� ���� �Լ�

struct node* make_Tree(int *pre_arr, int *post_arr, int* pre_index,int start_point, int end_point, int node_num){   

   int i;
   
    
     //���� �ε����� �����ε��� ���� ū���� return.
    if (*pre_index >= node_num || start_point > end_point)
        return NULL;
 
    
    struct node* root = newNode ( pre_arr[*pre_index] );
    *pre_index=*pre_index+1;
 
   //�� �ε����� ���� ��쿡�� ��Ʈ�� ��ȯ
    if (start_point == end_point){
      return root;
   }
   
    //������ȸ�� ������ȸ���� Unique�� Ʈ���� �ƴ� ��� Break���� 
    for (i = start_point; i <= end_point; ++i)
        if (pre_arr[*pre_index] == post_arr[i])
            break;
 
    
    //��������� Ʈ���� �������
    if (i <= end_point)
    {
        root->left = make_Tree(pre_arr, post_arr, pre_index, start_point, i, node_num);
        root->right = make_Tree(pre_arr, post_arr, pre_index, i + 1, end_point, node_num);
    }
 
    return root;
}
 


// ������ȸ ���
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
   int node_num =0; //��� ����
   int i;
   //���� ��ȸ �� ����� ���� �迭�Ҵ�
   int *pre_arr; 
   //���� ��ȸ �� ����� ���� �迭�Ҵ�
   int *post_arr;
   int pre_index = 0;
   struct node *root; 
  

       //Ʈ���� ��� �� �Է� 
	  printf("������ �Է��ϼ��� : ");
      scanf("%d", &node_num);

      //��� �� ��ŭ �������� �Ҵ��� �޾���
      pre_arr = (int*)malloc(sizeof(int*)*node_num); 
      post_arr = (int*)malloc(sizeof(int*)*node_num);

   
      //������ȸ ��� ���� �Է�
         for(i=0; i< node_num; i++){

            scanf("%d", &pre_arr[i]);
         }

      //������ȸ ��� ���� �Է�
         for(i=0; i< node_num; i++){

            scanf("%d", &post_arr[i]);
         }
   
   //������ȸ�� ù��° ���� Ʈ���� ��Ʈ�̴�.
    //����� ���� �ִ� �ε����� -1�����̹Ƿ� end_point�� ��尳������ 1�� ������ ����       
 
    root = make_Tree(pre_arr, post_arr, &pre_index, 0, node_num - 1, node_num);
 
    printf("������ȸ ��� \n");
   if(error_flag ==0){
    Inorder(root);
   }
   else{
      printf("unique�� tree�� �ƴմϴ�\n");
   }
      free(pre_arr);  //�Ҵ���� �����迭 �޸� ����
      free(post_arr);   
  
}

