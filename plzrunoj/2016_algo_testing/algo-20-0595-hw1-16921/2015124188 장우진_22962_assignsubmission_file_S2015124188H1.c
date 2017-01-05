#include<stdio.h>

void print_inorder(int node_num, int *pre, int *post){//Ʈ���� �������� �ʰ� �ο����� ��� (���)
	if (node_num == 1){                               // node_num : ����Ʈ���� ���� index : ����Ʈ �������� ���� ����Ʈ�� ��Ʈ�� ��ġ
		printf("%d ", pre[0]);
		return;
	}
	if (node_num == 3){
		printf("%d %d %d ",pre[1], pre[0], pre[2]);
		return;
	}
	int index = 0;
	while (post[index] != pre[1]) index++;  //���������� ù��° ���� ��Ʈ�� ����Ű��, �� �������� ���� ����Ʈ���� ��Ʈ�� ����Ų�� = index
	                                        //���� ����Ʈ���� �������� ������ �ΰ��� �ο��� ���� - ������ ������ ���
	print_inorder(index + 1, &pre[1], post);//���� ����Ʈ���� �ο����� ��� �� ��Ʈ ��� �� ������ ����Ʈ���� �ο����� ���
	printf("%d ", pre[0]);
	print_inorder(node_num - index - 2, &pre[2 + index], &post[index + 1]);
}

int main(){
	int pre_order[1000], post_order[1000];
	int num;

	scanf("%d", &num);//��� �� �Է�
	for (int i = 0; i < num; i++){//�������� �Է�
		scanf("%d", &pre_order[i]);
	}
	for (int i = 0; i < num; i++){//����Ʈ���� �Է�
		scanf("%d", &post_order[i]);
	}

	print_inorder(num, pre_order, post_order);//�ο��� ��� �Լ� ȣ��

	return 0;
}