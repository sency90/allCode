/*
알고리즘 과제 2016-12-5

2011122361 정수영 --- S2011122361H1.cpp

*/

#include<cstdio>
#include<iostream>

using namespace std;

int Pre[1000];
int In[1000];
int Post[1000];
int pre_check[1000];


void Inorder(int *pre, int *in, int *post, int size){ 
	int cnt =0;  //전위리스트에서 지운개수

	for(int post_index =0; post_index<size; post_index++){  //후위 인덱스 순회
		if(cnt == size){  //전위 갯수를 모두 채웠으면, 나온다
			return;
		}

		for(int pre_index=0; pre_index<size; pre_index++){  //전위 인덱스 순회

			if(post[post_index] == pre[pre_index]){     //전후와 후위가 같다면
				if(pre_index == 0 && pre_check[0] == 0){      //전위의 처음이고, 체크가 안됫을때,
					pre_check[0] = 1; //check하고
					in[cnt] = post[pre_index];
					cnt++;
					break;
				}

				if(pre_index != 0){   //전위의 처음이 아닐때
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
	int n; //1~1000까지 입력 
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){  //전위 입력
		scanf("%d",&Pre[i]);
	}

	for(int i=0; i<n; i++){  //후위입력
		scanf("%d",&Post[i]);
	}

	Inorder(Pre, In, Post, n);
	
	for(int i=0; i<n; i++){
		printf("%d ",In[i]);
	}printf("\n");
	
	return 0;
}