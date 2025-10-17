#include<cstdio>
#include<iostream>
#define MAX 1000
using namespace std;

int size;
int preorder[MAX];
int postorder[MAX];
bool flag[MAX] = {0,}; 

void inorder(int preStart, int preEnd, int postStart, int postEnd){


	int preRoot = preorder[preStart];
	int postRoot = postorder[postEnd];
	int postLeft = 0;

	if(preEnd - preStart <= 0 || postEnd - postStart <= 0){
		if(!flag[postEnd]){
			cout << postRoot << " ";
			flag[postEnd] = !flag[postEnd];
		}
	}
		return ;

	for(int i = postStart ; i <= postEnd ; i++){
		if(preorder[preStart + 1] == postorder[i]){ //왼쪽자식의 루트찾기
			postLeft = i;
		}
	}

	int preLeft = postLeft - postStart; 
	inorder(preStart+1, preStart + preLeft+1 , postStart , postLeft);

	if(!flag[postEnd]){ // flag -> 1 false를 뜻함
		cout << postRoot << " ";
		flag[postEnd] = !flag[postEnd];
	}

	inorder(preStart + preLeft + 2, preEnd , postLeft+1 , postEnd - 1);
}

int main(){
	cin >> size;
	for(int i = 0 ; i < size ; i++){
		cin >> preorder[i];
	} // input preoder
	for(int i = 0 ; i < size ; i++){
		cin >> postorder[i];
	} // input postorder
	
	inorder(0, size-1, 0, size-1);

	return 0;
}