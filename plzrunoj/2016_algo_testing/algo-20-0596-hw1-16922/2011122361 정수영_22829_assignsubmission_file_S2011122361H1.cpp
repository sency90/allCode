/*
�˰��� ���� 2016-12-5

2011122361 ������ --- S2011122361H1.cpp

*/

#include<cstdio>
#include<iostream>

using namespace std;

int Pre[1000];
int In[1000];
int Post[1000];
int pre_check[1000];


void Inorder(int *pre, int *in, int *post, int size){ 
	int cnt =0;  //��������Ʈ���� �����

	for(int post_index =0; post_index<size; post_index++){  //���� �ε��� ��ȸ
		if(cnt == size){  //���� ������ ��� ä������, ���´�
			return;
		}

		for(int pre_index=0; pre_index<size; pre_index++){  //���� �ε��� ��ȸ

			if(post[post_index] == pre[pre_index]){     //���Ŀ� ������ ���ٸ�
				if(pre_index == 0 && pre_check[0] == 0){      //������ ó���̰�, üũ�� �ȵ�����,
					pre_check[0] = 1; //check�ϰ�
					in[cnt] = post[pre_index];
					cnt++;
					break;
				}

				if(pre_index != 0){   //������ ó���� �ƴҶ�
					if(pre_check[pre_index] == 0){ 
						in[cnt] = pre[pre_index];
						pre_check[pre_index] = 1;
						cnt++;
					}
					if(pre_check[pre_index - 1] == 0){
						in[cnt] = pre[pre_index -1];
						pre_check[pre_index - 1] = 1;
						cnt++;
					}break;
				}
			}
		}
	}
}

int main(){
	int n; //1~1000���� �Է� 
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){  //���� �Է�
		scanf("%d",&Pre[i]);
	}

	for(int i=0; i<n; i++){  //�����Է�
		scanf("%d",&Post[i]);
	}

	Inorder(Pre, In, Post, n);
	
	for(int i=0; i<n; i++){
		printf("%d ",In[i]);
	}printf("\n");
	
	return 0;
}