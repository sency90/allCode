/*
*전위순회와 후위순회 값을 받아 중위순회를 출력하는 프로그램
*/

#include <stdio.h>

int in_order[1000];		//중위순회 결과값을 저장 할 배열

int search(int arr[], int x, int n) {	//루트값의 위치를 찾아주는 함수
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) return i+1;
	}
}

void Print_InOrder(int pre[], int post[], int n, int p) {	//in_order에 저장할 값들을 구하는 함수
	int pre_order_left[1000];	//전위순회 왼쪽 자식
	int post_order_left[1000];	//후위순회 왼쪽 자식
	int pre_order_right[1000];	//전위순회 오른쪽 자식
	int post_order_right[1000];	//후위순회 오른쪽 자식

	if (n == 1) {		//현재 노드에 더이상 자식이 없을 때
		int temp = 0;
		in_order[temp + p] = pre[0];
	}
	else {
		int temp = search(post, pre[1], n);		//temp에 루트값의 위치 저장
		for (int i = 0; i < n; i++) {
			in_order[temp + p] = pre[0];		//in_order에 현재 pre_order의 첫번쨰 값 즉, 루트값 저장
			//왼쪽
			for (int j = 0; j < temp; j++) {
				pre_order_left[j] = pre[j + 1];	//전위순회의 왼쪽 자식들 저장
				post_order_left[j] = post[j];	//후위순회의 왼쪽 자식들 저장
			}
			//오른쪽
			for (int k = 0; k < n - temp - 1; k++) {
				pre_order_right[k] = pre[temp + 1 + k];	//전위 순회의 오른쪽 자식들 저장
				post_order_right[k] = post[temp + k];	//후위 순회의 오른쪽 자식들 저장
			}
			Print_InOrder(pre_order_left, post_order_left, temp, p);	//전위, 후위순회의 왼쪽 자식들을 대상으로 함수 호출
			Print_InOrder(pre_order_right, post_order_right, n - temp - 1, temp+p+1);	//전위, 후위순회의 오른쪽 자식들을 대상으로 함수 호출
		}
	}
}

int main() {
	int node;	//입력받는 노드의 개수
	int pre_order[1000];	//전위순회를 저장할 배열
	int post_order[1000];	//후위순회를 저장할 배열

	scanf_s("%d", &node);	//노드의 개수를 받는다.
	for (int i = 0; i < node; i++) {	//전위순회의 값들을 입력 받는다.
		scanf_s("%d", &pre_order[i]);
	}
	for (int j = 0; j < node; j++) {	//후위순회의 값들을 입력 받는다.
		scanf_s("%d", &post_order[j]);
	}
	
	Print_InOrder(pre_order, post_order, node, 0);	//함수 호출

	for (int k = 0; k < node; k++) {	//중위순회 결과값 출력
		printf_s("%d ", in_order[k]);
	}
}