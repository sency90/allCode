#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

void find(int a[], int b[], int num, int plus, int result[]) {
	int i;			//반복문 변수
	int rootNum;	//루트 노드 인덱스
	
	if (num == 1) {
		//재귀함수 종료조건
		rootNum = 0;
		result[rootNum + plus] = a[0];
	}
	else {
		//루트 노드 찾기
		for (i = 0; i < num; i++) {
			if (b[i] == a[1]) {
				//갯수는 인텍스 + 1
				rootNum = i + 1;
			}
		}
		//중위순회 결과에 대입 - 루트 노드 왼쪽은 왼쪽자식, 오른쪽은 오른쪽자식이므로 중간이 루트
		result[rootNum + plus] = a[0];

		//전위순회와 후위순회의 왼쪽, 오른쪽 자식 배열 나누기
		int *a1 = new int[rootNum], *b1 = new int[rootNum];
		int *a2 = new int[num - rootNum - 1], *b2 = new int[num - rootNum - 1];
		for (i = 0; i < num - 1; i++) {
			if (i < rootNum) {
				//왼쪽 자식 배열
				a1[i] = a[i + 1];
				b1[i] = b[i];
			}
			else {
				//오른쪽 자식 배열
				a2[i - rootNum] = a[i + 1];
				b2[i - rootNum] = b[i];
			}
		}
		//재귀함수
		find(a1, b1, rootNum, plus, result);
		find(a2, b2, num - rootNum - 1, rootNum + 1 + plus, result);
	}
}

void main() {
	int i;			//반복문 변수
	int nodeNum;	//노드 갯수
	
	while (true) {
		scanf("%d", &nodeNum);
		if (nodeNum > 1000 || nodeNum < 1) {		//노드 갯수 범위 밖일 때
			printf("1부터 1000 이내의 수 입력\n");
			continue;
		}
		break;
	}
	//순회 결과 배열 동적할당
	int *pre = new int[nodeNum];
	int *post = new int[nodeNum];
	int *in = new int[nodeNum];

	//전위 순회 입력
	for (i = 0; i < nodeNum; i++) {
		scanf("%d",&pre[i]);
	}
	//후위 순회 입력
	for (i = 0; i < nodeNum; i++) {
		scanf("%d",&post[i]);
	}

	//중위 순회 탐색
	find(pre, post, nodeNum, 0, in);
	
	//중위 순회 결과
	for (i = 0; i < nodeNum; i++)
		printf("%d ",in[i]);
	printf("\n");
}
