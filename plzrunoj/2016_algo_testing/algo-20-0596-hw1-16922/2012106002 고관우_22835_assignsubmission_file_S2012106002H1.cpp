/* 이 문제에 대한 모순

 case1          case2 
   1              1
 2                  2

 모두 전위 순회시 :: 1 2 후위 순회시 :: 2 1이다

 전위, 중위가 주어졌을 때 후위 순회를 구하는 것은 모순이 일어나지 않지만,
 전위, 후위가 주어졌을 때 중위 순회를 구하는 것은 위와같이 모순점이 발생한다.

 따라서 아래 코드는 case1을 기준으로 제작하였다.
*/
#include <cstdio>
#include <iostream>

using namespace std;

#define nodeNum 1002

/*
left :: 현재 노드의 왼쪽 자식 노드 번호
right :: 현재 노드의 오른쪽 자식 노드 번호
chk :: 현재 노드가 이용되는지 여부
parent :: 현재 노드의 부모 노드 번호
*/
struct _tree
{
	int left;
	int right;
	int chk;
	int parent;
};

// tree :: pre, post를 통해 정보를 알아내는 구조체
// pre :: 전위 순회 결과가 있는 배열
// post :: 후위 순회 결과가 있는 배열
struct _tree tree[nodeNum];
int pre[nodeNum];
int post[nodeNum];
int n;

void getTree(int num)
{
	// pre의 num번째 값을 now로 받아낸다.
	int now = pre[num];

	// tree의 now번째가 결국 방문된 것이므로 chk를 1로 설정
	tree[now].chk = 1;

	int tmp = 1;

	// 전위 순회의 다음 값과 후위 순회의 값이 같아지는 tmp를 구한다.
	while (tmp <= n && post[tmp] != pre[num + 1])
		tmp++;

	if (tmp > n)
		return;

	// 후위 순회의 tmp번째 값의 부모가 없다면, 아래 처럼 설정해준다.
	if (tree[post[tmp]].parent == -1)
	{
		tree[now].left = post[tmp];
		tree[post[tmp]].parent = now;
	}

	// 전위 순회의 값과 후위 순회의 값이 같아지는 tmp를 구한다.
	while (tmp <= n && post[tmp] != pre[num])
		tmp++;

	if (tmp > n)
		return;

	// 후위 순회의 tmp-1번째 값의 부모가 없다면, 아래 처럼 설정해준다.
	if (tree[post[tmp - 1]].parent == -1)
	{
		tree[now].right = post[tmp - 1];
		tree[post[tmp - 1]].parent = now;
	}

	// 전위 순회 배열에서 현재 왼쪽 자식 노드와 같은 값이 있는
	// 배열 번호를 getTree에 넣어준다.
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] == tree[now].left)
			getTree(i);
	}

	// 전위 순회 배열에서 현재 오른쪽 자식 노드와 같은 값이 있는
	// 배열 번호를 getTree에 넣어준다.
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] == tree[now].right)
			getTree(i);
	}
}

// 중위 순회
void InorderTraverse(int now)
{
	if (now == -1 || tree[now].chk == -1)
		return;

	InorderTraverse(tree[now].left);

	printf("%d ", now);

	InorderTraverse(tree[now].right);

}


int main()
{
	int start;

	// 초기화 (1부터 시작일수도있으니 1002개를 초기화.)
	for (int i = 0; i < nodeNum; i++)
	{
		tree[i].chk = -1;
		tree[i].right = -1;
		tree[i].left = -1;
		tree[i].parent = -1;
	}

	fill(pre, pre + nodeNum, -1);
	fill(post, post + nodeNum, -1);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &pre[i]);

	for (int i = 1; i <= n; i++)
		scanf("%d", &post[i]);

	start = 1;
	getTree(start);

	// 검증
	// for (int i = 1; i <= n; i++)
	//    printf("노드 :: %d, 체크 :: %d, L자식 :: %d, R자식 :: %d, 부모 :: %d\n",i,tree[i].chk,tree[i].left,tree[i].right,tree[i].parent);


	InorderTraverse(pre[1]);
	return 0;
}
