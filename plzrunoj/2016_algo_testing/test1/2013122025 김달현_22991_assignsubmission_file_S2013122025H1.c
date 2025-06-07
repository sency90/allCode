/*
*������ȸ�� ������ȸ ���� �޾� ������ȸ�� ����ϴ� ���α׷�
*/

#include <stdio.h>

int in_order[1000];		//������ȸ ������� ���� �� �迭

int search(int arr[], int x, int n) {	//��Ʈ���� ��ġ�� ã���ִ� �Լ�
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) return i+1;
	}
}

void Print_InOrder(int pre[], int post[], int n, int p) {	//in_order�� ������ ������ ���ϴ� �Լ�
	int pre_order_left[1000];	//������ȸ ���� �ڽ�
	int post_order_left[1000];	//������ȸ ���� �ڽ�
	int pre_order_right[1000];	//������ȸ ������ �ڽ�
	int post_order_right[1000];	//������ȸ ������ �ڽ�

	if (n == 1) {		//���� ��忡 ���̻� �ڽ��� ���� ��
		int temp = 0;
		in_order[temp + p] = pre[0];
	}
	else {
		int temp = search(post, pre[1], n);		//temp�� ��Ʈ���� ��ġ ����
		for (int i = 0; i < n; i++) {
			in_order[temp + p] = pre[0];		//in_order�� ���� pre_order�� ù���� �� ��, ��Ʈ�� ����
			//����
			for (int j = 0; j < temp; j++) {
				pre_order_left[j] = pre[j + 1];	//������ȸ�� ���� �ڽĵ� ����
				post_order_left[j] = post[j];	//������ȸ�� ���� �ڽĵ� ����
			}
			//������
			for (int k = 0; k < n - temp - 1; k++) {
				pre_order_right[k] = pre[temp + 1 + k];	//���� ��ȸ�� ������ �ڽĵ� ����
				post_order_right[k] = post[temp + k];	//���� ��ȸ�� ������ �ڽĵ� ����
			}
			Print_InOrder(pre_order_left, post_order_left, temp, p);	//����, ������ȸ�� ���� �ڽĵ��� ������� �Լ� ȣ��
			Print_InOrder(pre_order_right, post_order_right, n - temp - 1, temp+p+1);	//����, ������ȸ�� ������ �ڽĵ��� ������� �Լ� ȣ��
		}
	}
}

int main() {
	int node;	//�Է¹޴� ����� ����
	int pre_order[1000];	//������ȸ�� ������ �迭
	int post_order[1000];	//������ȸ�� ������ �迭

	scanf_s("%d", &node);	//����� ������ �޴´�.
	for (int i = 0; i < node; i++) {	//������ȸ�� ������ �Է� �޴´�.
		scanf_s("%d", &pre_order[i]);
	}
	for (int j = 0; j < node; j++) {	//������ȸ�� ������ �Է� �޴´�.
		scanf_s("%d", &post_order[j]);
	}
	
	Print_InOrder(pre_order, post_order, node, 0);	//�Լ� ȣ��

	for (int k = 0; k < node; k++) {	//������ȸ ����� ���
		printf_s("%d ", in_order[k]);
	}
}