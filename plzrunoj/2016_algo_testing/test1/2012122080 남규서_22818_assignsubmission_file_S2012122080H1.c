#include <stdio.h>

void inOrder(int * pre, int * post, int cnt){
	
	if(cnt == 1)
		printf("%d ", pre[0]);
	// 배열 크기가 2인 경우 후위순회의 앞쪽 노드를 먼저 출력
	else if(cnt == 2)
		printf("%d %d " , post[0], post[1]);
	// 배열 크기가 3인 경우 전위순회의 2번째 노드와 후위순회의 첫번째 노드가 같은가에 따라 다른결과가 나온다
	else if(cnt ==3){
		if(pre[1] != post[0])
			printf("%d %d %d ", pre[1], pre[2], pre[0]);
		else
			printf("%d %d %d ", post[0], post[2], post[1]);
	}

	//위의 세가지 경우는 왼쪽자식, 오른쪽자식에 관한 규칙이 정해져 있으므로 규칙대로 해당 값을 출력한다

	//아래는 길이가 4이상인 배열의 경우
	else{
		int root = post[cnt-1];
		int rightRoot = post[cnt -2];
		int index = 0;
		//후위순회 결과에서 현재 루트노드와 오른쪽 서브트리의 루트값을 받아온다

		for(int i=0; i<cnt; i++){
			if(pre[i] == rightRoot)
				index = i;
		}

		// 전위순회에서 오른쪽 서브트리의 루트값이 어디에 위치하는지를 찾는다

		int *preLeftSub = new int[index-1];
		int *preRightSub = new int[cnt - index];

		// 찾은 index값을 이용해 전위순회를 왼쪽 서브트리, 오른쪽 서브트리의 배열 2개로 나눈다

		for(int i = 1; i<=cnt; i++){
			if(i<index)
				preLeftSub[i-1] = pre[i];
			else if(i>=index)
				preRightSub[i-index] = pre[i];
		}

		// 아래는 마찬가지로 후위순회를 왼쪽 서브트리, 오른쪽 서브트리 배열 2개로 나눔

		int *postLeftSub = new int[index];
		int *postRightSub = new int[cnt - index];

		for (int i = 0; i<cnt - 1; i++){
			if(i<index - 1)
				postLeftSub[i] = post[i];
			else if(i>=index - 1)
				postRightSub[i - (index-1)] = post[i];
		}

		// 전위순회에서 구한 왼쪽, 오른쪽 서브트리 배열, 후위순회에서 구한 왼쪽,오른쪽 서브트리 배열과 index값을 이용해
		// 이를 재귀적으로 반복하면서 root값을 출력한다
		inOrder(preLeftSub, postLeftSub, index-1);
		printf("%d ", root);
		inOrder(preRightSub, postRightSub, cnt-index);

		delete[]preLeftSub;
		delete[]preRightSub;
		delete[]postLeftSub;
		delete[]postRightSub;
		// 메모리 해제
	}
}

int main(){
	int nodeCount = 0;
	scanf("%d", &nodeCount);

	int *preOrder  = new int[nodeCount];
	int *postOrder = new int[nodeCount];

	for(int i = 0; i<nodeCount; i++){
		scanf("%d", &preOrder[i]);
	}

	for(int i = 0; i<nodeCount; i++){
		scanf("%d", &postOrder[i]);
	}

	printf("\n");
	inOrder(preOrder, postOrder, nodeCount);
	// 중위순회 결과를 출력하는 함수 호출
	printf("\n");

	delete[] preOrder;
	delete[] postOrder;
	//사용하지 않는 배열 메모리 해제

	return 0;
}
