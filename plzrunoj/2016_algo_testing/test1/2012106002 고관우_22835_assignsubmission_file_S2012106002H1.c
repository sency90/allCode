#include <cstdio>
#include <iostream>

using namespace std;

#define nodeNum 1002

struct _tree
{
	int left;
	int right;
	int chk;
	int parent;
};

struct _tree tree[nodeNum];
int pre[nodeNum];
int post[nodeNum];
int n;

void getTree(int num)
{
	// pre�� num��° ���� now�� �޾Ƴ���.
	int now = pre[num];

	// tree�� now��°�� �ᱹ �湮�� ���̹Ƿ� chk�� 1�� ����
	tree[now].chk = 1;

	int tmp = 1;

	// ���� ��ȸ�� ���� ���� ���� ��ȸ�� ���� �������� tmp�� ���Ѵ�.
	while (tmp <= n && post[tmp] != pre[num + 1])
		tmp++;

	if (tmp > n)
		return;

	// ���� ��ȸ�� tmp��° ���� �θ� ���ٸ�, �Ʒ� ó�� �������ش�.
	if (tree[post[tmp]].parent == -1)
	{
		tree[now].left = post[tmp];
		tree[post[tmp]].parent = now;
	}

	// ���� ��ȸ�� ���� ���� ��ȸ�� ���� �������� tmp�� ���Ѵ�.
	while (tmp <= n && post[tmp] != pre[num])
		tmp++;

	if (tmp > n)
		return;

	// ���� ��ȸ�� tmp-1��° ���� �θ� ���ٸ�, �Ʒ� ó�� �������ش�.
	if (tree[post[tmp - 1]].parent == -1)
	{
		tree[now].right = post[tmp - 1];
		tree[post[tmp - 1]].parent = now;
	}

	// ���� ��ȸ �迭���� ���� ���� �ڽ� ���� ���� ���� �ִ�
	// �迭 ��ȣ�� getTree�� �־��ش�.
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] == tree[now].left)
			getTree(i);
	}

	// ���� ��ȸ �迭���� ���� ������ �ڽ� ���� ���� ���� �ִ�
	// �迭 ��ȣ�� getTree�� �־��ش�.
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] == tree[now].right)
			getTree(i);
	}
}

// ���� ��ȸ
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

	// �ʱ�ȭ (1���� �����ϼ��������� 1002���� �ʱ�ȭ.)
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

	// ����
	// for (int i = 1; i <= n; i++)
	//    printf("��� :: %d, üũ :: %d, L�ڽ� :: %d, R�ڽ� :: %d, �θ� :: %d\n",i,tree[i].chk,tree[i].left,tree[i].right,tree[i].parent);


	InorderTraverse(pre[1]);
	return 0;
}
