#include <stdio.h>
#include <algorithm>
#include <vector>
// vector, heap�� ����ϱ� ���� algorithm, vector ��� ����

int arrInt[10000];
// �ִ� �� �� �ִ� �Է��� 1000����

int main(){
	int numberCount = 0;
	scanf("%d",&numberCount);

	for(int i = 0; i<numberCount; i++)
		scanf("%d", &arrInt[i]);

	int maxNumber = 0;

	std::vector<int> vi(&arrInt[0], &arrInt[numberCount]);
	// �Է¹��� int�� �迭�� heap���鶧 ����ϱ� ���� ���ͷ� ��ȯ�Ѵ�

	std::make_heap(vi.begin(), vi.end());
	std::sort_heap(vi.begin(), vi.end());
	//���͸� �̿��� ���� ����� heap_sort�� �����Ѵ�

	for(int i = 0; i<numberCount; i++){
		if( vi[i] >= numberCount - i){
			// �迭ũ�⿡�� �ڽ��� index�� ���� �ڱ⺸�� ���ų� ū ������ ���� �� �� �ִ�
			// �̸� �ڱ��ڽŰ� ���Ͽ� ���ǿ� �´´ٸ�
			maxNumber = numberCount - i;
			// ���ǿ� �´� x�� maxNumber�� ����
			break;
			// ������������ ���ĵǾ��ֱ� ������ �ڿ� ���Ҵ� ������ �ʾƵ� �ȴ�

		}
	}
	
	printf("%d\n", maxNumber);
	//���ǿ� �´� x�� �ִ밪 ���

	return 0;
}