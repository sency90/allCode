#include <stdio.h>

void inOrder(int * pre, int * post, int cnt){
	
	if(cnt == 1)
		printf("%d ", pre[0]);
	// �迭 ũ�Ⱑ 2�� ��� ������ȸ�� ���� ��带 ���� ���
	else if(cnt == 2)
		printf("%d %d " , post[0], post[1]);
	// �迭 ũ�Ⱑ 3�� ��� ������ȸ�� 2��° ���� ������ȸ�� ù��° ��尡 �������� ���� �ٸ������ ���´�
	else if(cnt ==3){
		if(pre[1] != post[0])
			printf("%d %d %d ", pre[1], pre[2], pre[0]);
		else
			printf("%d %d %d ", post[0], post[2], post[1]);
	}

	//���� ������ ���� �����ڽ�, �������ڽĿ� ���� ��Ģ�� ������ �����Ƿ� ��Ģ��� �ش� ���� ����Ѵ�

	//�Ʒ��� ���̰� 4�̻��� �迭�� ���
	else{
		int root = post[cnt-1];
		int rightRoot = post[cnt -2];
		int index = 0;
		//������ȸ ������� ���� ��Ʈ���� ������ ����Ʈ���� ��Ʈ���� �޾ƿ´�

		for(int i=0; i<cnt; i++){
			if(pre[i] == rightRoot)
				index = i;
		}

		// ������ȸ���� ������ ����Ʈ���� ��Ʈ���� ��� ��ġ�ϴ����� ã�´�

		int *preLeftSub = new int[index-1];
		int *preRightSub = new int[cnt - index];

		// ã�� index���� �̿��� ������ȸ�� ���� ����Ʈ��, ������ ����Ʈ���� �迭 2���� ������

		for(int i = 1; i<=cnt; i++){
			if(i<index)
				preLeftSub[i-1] = pre[i];
			else if(i>=index)
				preRightSub[i-index] = pre[i];
		}

		// �Ʒ��� ���������� ������ȸ�� ���� ����Ʈ��, ������ ����Ʈ�� �迭 2���� ����

		int *postLeftSub = new int[index];
		int *postRightSub = new int[cnt - index];

		for (int i = 0; i<cnt - 1; i++){
			if(i<index - 1)
				postLeftSub[i] = post[i];
			else if(i>=index - 1)
				postRightSub[i - (index-1)] = post[i];
		}

		// ������ȸ���� ���� ����, ������ ����Ʈ�� �迭, ������ȸ���� ���� ����,������ ����Ʈ�� �迭�� index���� �̿���
		// �̸� ��������� �ݺ��ϸ鼭 root���� ����Ѵ�
		inOrder(preLeftSub, postLeftSub, index-1);
		printf("%d ", root);
		inOrder(preRightSub, postRightSub, cnt-index);

		delete[]preLeftSub;
		delete[]preRightSub;
		delete[]postLeftSub;
		delete[]postRightSub;
		// �޸� ����
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
	// ������ȸ ����� ����ϴ� �Լ� ȣ��
	printf("\n");

	delete[] preOrder;
	delete[] postOrder;
	//������� �ʴ� �迭 �޸� ����

	return 0;
}
