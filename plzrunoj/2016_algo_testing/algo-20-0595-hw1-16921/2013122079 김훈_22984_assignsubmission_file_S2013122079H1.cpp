#include<stdio.h>
int inorder[1000];	//���� ��ȸ ��� ������ �迭 ����
void Check_Root(int* pre, int*post, int size, int plus) {	//����, ���� ��ȸ ����� ũ��, �������� �Է¹޾� ���� Ʈ������ ������ȸ�� ��Ʈ�� ��ġ�� ���ϴ� �Լ� ����
	int root_index;	//���� ��ȸ������ ��Ʈ ��ġ�� ������ ���� ����
	if (size == 1) {	//����Լ� ���� �� ����� ���� 1�� ���
		root_index = 0;	//�κ������� ��Ʈ�� ��ġ�� 0��° �̴�.
		inorder[root_index + plus] = pre[0];	//�ش� ����� data�� ������ȸ �迭�� �ش� �ε����� ����
	}
	for (int i = 0; i < size; i++) {	//��ü ��带 Ž���Ѵ�.
		if (post[size - 2] == pre[1]) {	//��Ʈ�� ���� ��尡 ���� ���
			root_index = 0;	//��Ʈ�� ��ġ�� 0��°�̴�.
			inorder[root_index + plus] = pre[0];	//�ش� ����� data�� ������ȸ �迭�� �ش� �ε����� ����
			int *make_pre_pre = new int[root_index];	//��Ʈ�� �������� ������ �ִ� ������ ������ȸ �迭 �����Ҵ�
			int *make_pre_post = new int[root_index];	//��Ʈ�� �������� ������ �ִ� ������ ������ȸ �迭 �����Ҵ�
			int *make_post_pre = new int[size - root_index - 1];	//��Ʈ�� �������� ������ �ִ� ������ ������ȸ �迭 �����Ҵ�
			int *make_post_post = new int[size - root_index - 1];	//��Ʈ�� �������� ������ �ִ� ������ ������ȸ �迭 �����Ҵ�
			for (int i = 0; i < root_index; i++) {	//��Ʈ�� �������� ������ �ִ� ������ ��, ���� ��ȸ �迭�� �� ����
				make_pre_pre[i] = pre[i + 1];
				make_pre_post[i] = post[i];
			}
			for (int i = 0; i < size - root_index - 1; i++) {	//��Ʈ�� �������� ������ �ִ� ������ ��, ���� ��ȸ �迭�� �� ����
				make_post_pre[i] = pre[root_index + 1 + i];
				make_post_post[i] = post[root_index + i];
			}
			Check_Root(make_pre_pre, make_pre_post, root_index, plus);	//��Ʈ�� �������� ������ �ִ� ������ ��Ʈã��(����Լ� ȣ��)
			Check_Root(make_post_pre, make_post_post, size - root_index - 1, root_index + 1 + plus);	//��Ʈ�� �������� ������ �ִ� ������ ��Ʈã��
		}
		else if (post[i] == pre[1]) {	//������ȸ���� ��Ʈ ������ ����, �� ��Ʈ�� �����ڽİ� ������ȸ������ ��ġ�� ã�´�. 
			root_index = i + 1;	//���� ��ȸ���� �ش� ��ġ�� ��Ʈ�� �����ڽ��� ���� �� ��带 �ǹ��ϹǷ� ������ȸ���� ��Ʈ �ٷ� �տ� �´�.
			inorder[root_index+plus] = pre[0];//�ش� ����� data�� ������ȸ �迭�� �ش� �ε����� ����
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
	int node_count;	//����� ���� �Է¹��� ���� ����
	scanf_s("%d", &node_count);	//����� �� �Է�
	int preorder[1000];	//������ȸ�� ������ �迭 ����
	int postorder[1000];//������ȸ�� ������ �迭 ����
	for (int i = 0; i < node_count; i++)	scanf_s("%d", &preorder[i]);	//������ȸ�� �Է�
	for (int i = 0; i < node_count; i++)	scanf_s("%d", &postorder[i]);	//������ȸ�� �Է�
	Check_Root(preorder, postorder, node_count,0);	//��Ʈ�� ã�� ������ȸ���� �����ϴ� �Լ� ȣ��
	for (int i = 0; i < node_count; i++)	printf_s("%d ", inorder[i]);	//������ȸ�� ���
	return 0;
}