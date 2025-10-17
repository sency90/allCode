#include<stdio.h>

void print_inorder(int node_num, int *pre, int *post){//트리를 구현하지 않고 인오더로 출력 (재귀)
	if (node_num == 1){                               // node_num : 서브트리의 노드수 index : 포스트 오더에서 왼쪽 서브트리 루트의 위치
		printf("%d ", pre[0]);
		return;
	}
	if (node_num == 3){
		printf("%d %d %d ",pre[1], pre[0], pre[2]);
		return;
	}
	int index = 0;
	while (post[index] != pre[1]) index++;  //프리오더의 첫번째 노드는 루트를 가리키고, 그 다음노드는 왼쪽 서브트리의 루트를 가리킨다 = index
	                                        //왼쪽 서브트리가 존재하지 않으면 두가지 인오더 나옴 - 문제의 조건을 어김
	print_inorder(index + 1, &pre[1], post);//왼쪽 서브트리를 인오더로 출력 후 루트 출력 후 오른쪽 서브트리를 인오더로 출력
	printf("%d ", pre[0]);
	print_inorder(node_num - index - 2, &pre[2 + index], &post[index + 1]);
}

int main(){
	int pre_order[1000], post_order[1000];
	int num;

	scanf("%d", &num);//노드 수 입력
	for (int i = 0; i < num; i++){//프리오더 입력
		scanf("%d", &pre_order[i]);
	}
	for (int i = 0; i < num; i++){//포스트오더 입력
		scanf("%d", &post_order[i]);
	}

	print_inorder(num, pre_order, post_order);//인오더 출력 함수 호출

	return 0;
}