#include<stdio.h>
int inorder[1000];	//중위 순회 결과 저장할 배열 설정
void Check_Root(int* pre, int*post, int size, int plus) {	//전위, 후위 순회 결과와 크기, 보정값을 입력받아 현재 트리에서 중위순회에 루트의 위치를 구하는 함수 선언
	int root_index;	//중위 순회에서의 루트 위치를 저장할 변수 선언
	if (size == 1) {	//재귀함수 실행 시 노드의 수가 1일 경우
		root_index = 0;	//부분적으로 루트의 위치는 0번째 이다.
		inorder[root_index + plus] = pre[0];	//해당 노드의 data를 중위순회 배열의 해당 인덱스에 대입
	}
	for (int i = 0; i < size; i++) {	//전체 노드를 탐색한다.
		if (post[size - 2] == pre[1]) {	//루트의 왼쪽 노드가 없을 경우
			root_index = 0;	//루트의 위치는 0번째이다.
			inorder[root_index + plus] = pre[0];	//해당 노드의 data를 중위순회 배열의 해당 인덱스에 대입
			int *make_pre_pre = new int[root_index];	//루트를 기준으로 좌측에 있는 노드들의 전위순회 배열 동적할당
			int *make_pre_post = new int[root_index];	//루트를 기준으로 좌측에 있는 노드들의 후위순회 배열 동적할당
			int *make_post_pre = new int[size - root_index - 1];	//루트를 기준으로 우측에 있는 노드들의 전위순회 배열 동적할당
			int *make_post_post = new int[size - root_index - 1];	//루트를 기준으로 우측에 있는 노드들의 후위순회 배열 동적할당
			for (int i = 0; i < root_index; i++) {	//루트를 기준으로 좌측에 있는 노드들의 전, 후위 순회 배열에 값 대입
				make_pre_pre[i] = pre[i + 1];
				make_pre_post[i] = post[i];
			}
			for (int i = 0; i < size - root_index - 1; i++) {	//루트를 기준으로 우측에 있는 노드들의 전, 후위 순회 배열에 값 대입
				make_post_pre[i] = pre[root_index + 1 + i];
				make_post_post[i] = post[root_index + i];
			}
			Check_Root(make_pre_pre, make_pre_post, root_index, plus);	//루트를 기준으로 좌측에 있는 노드들의 루트찾기(재귀함수 호출)
			Check_Root(make_post_pre, make_post_post, size - root_index - 1, root_index + 1 + plus);	//루트를 기준으로 우측에 있는 노드들의 루트찾기
		}
		else if (post[i] == pre[1]) {	//전위순회에서 루트 다음에 오는, 즉 루트의 왼쪽자식과 후위순회에서의 위치를 찾는다. 
			root_index = i + 1;	//후위 순회에서 해당 위치는 루트의 왼쪽자식의 가장 위 노드를 의미하므로 중위순회에서 루트 바로 앞에 온다.
			inorder[root_index+plus] = pre[0];//해당 노드의 data를 중위순회 배열의 해당 인덱스에 대입
			int *make_pre_pre = new int[root_index];
			int *make_pre_post = new int[root_index];
			int *make_post_pre = new int[size - root_index - 1];
			int *make_post_post = new int[size - root_index - 1];
			for (int i = 0; i < root_index; i++) {
				make_pre_pre[i] = pre[i + 1];
				make_pre_post[i] = post[i];
			}
			for (int i = 0; i < size - root_index - 1; i++) {
				make_post_pre[i] = pre[root_index + 1 + i];
				make_post_post[i] = post[root_index + i];
			}
			Check_Root(make_pre_pre, make_pre_post, root_index, plus);
			Check_Root(make_post_pre, make_post_post, size - root_index - 1, root_index + 1+plus);
		}
	}

}
int main() {
	int node_count;	//노드의 수를 입력받을 변수 선언
	scanf_s("%d", &node_count);	//노드의 수 입력
	int preorder[1000];	//전위순회를 저장할 배열 선언
	int postorder[1000];//후위순회를 저장할 배열 선언
	for (int i = 0; i < node_count; i++)	scanf_s("%d", &preorder[i]);	//전위순회값 입력
	for (int i = 0; i < node_count; i++)	scanf_s("%d", &postorder[i]);	//후위순회값 입력
	Check_Root(preorder, postorder, node_count,0);	//루트를 찾아 중위순회값을 저장하는 함수 호출
	for (int i = 0; i < node_count; i++)	printf_s("%d ", inorder[i]);	//중위순회값 출력
	return 0;
}