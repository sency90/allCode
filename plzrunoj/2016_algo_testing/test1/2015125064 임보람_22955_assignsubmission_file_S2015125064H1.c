#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

void find(int a[], int b[], int num, int plus, int result[]) {
	int i;			//�ݺ��� ����
	int rootNum;	//��Ʈ ��� �ε���
	
	if (num == 1) {
		//����Լ� ��������
		rootNum = 0;
		result[rootNum + plus] = a[0];
	}
	else {
		//��Ʈ ��� ã��
		for (i = 0; i < num; i++) {
			if (b[i] == a[1]) {
				//������ ���ؽ� + 1
				rootNum = i + 1;
			}
		}
		//������ȸ ����� ���� - ��Ʈ ��� ������ �����ڽ�, �������� �������ڽ��̹Ƿ� �߰��� ��Ʈ
		result[rootNum + plus] = a[0];

		//������ȸ�� ������ȸ�� ����, ������ �ڽ� �迭 ������
		int *a1 = new int[rootNum], *b1 = new int[rootNum];
		int *a2 = new int[num - rootNum - 1], *b2 = new int[num - rootNum - 1];
		for (i = 0; i < num - 1; i++) {
			if (i < rootNum) {
				//���� �ڽ� �迭
				a1[i] = a[i + 1];
				b1[i] = b[i];
			}
			else {
				//������ �ڽ� �迭
				a2[i - rootNum] = a[i + 1];
				b2[i - rootNum] = b[i];
			}
		}
		//����Լ�
		find(a1, b1, rootNum, plus, result);
		find(a2, b2, num - rootNum - 1, rootNum + 1 + plus, result);
	}
}

void main() {
	int i;			//�ݺ��� ����
	int nodeNum;	//��� ����
	
	while (true) {
		scanf("%d", &nodeNum);
		if (nodeNum > 1000 || nodeNum < 1) {		//��� ���� ���� ���� ��
			printf("1���� 1000 �̳��� �� �Է�\n");
			continue;
		}
		break;
	}
	//��ȸ ��� �迭 �����Ҵ�
	int *pre = new int[nodeNum];
	int *post = new int[nodeNum];
	int *in = new int[nodeNum];

	//���� ��ȸ �Է�
	for (i = 0; i < nodeNum; i++) {
		scanf("%d",&pre[i]);
	}
	//���� ��ȸ �Է�
	for (i = 0; i < nodeNum; i++) {
		scanf("%d",&post[i]);
	}

	//���� ��ȸ Ž��
	find(pre, post, nodeNum, 0, in);
	
	//���� ��ȸ ���
	for (i = 0; i < nodeNum; i++)
		printf("%d ",in[i]);
	printf("\n");
}
