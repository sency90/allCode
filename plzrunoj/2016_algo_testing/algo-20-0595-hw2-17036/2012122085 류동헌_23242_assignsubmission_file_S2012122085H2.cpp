#include<stdio.h>
#include<vector>

using namespace std;

int main() {

	vector<int> number;

	int n = 0;
	scanf("%d", &n);			//�Է¹��� ������ ���� ����
//	printf("\n");

	//vector�� ���ڵ� �迭�� ����
	for (int i = 0; i < n; i++) {
		int temp = 0;		//������ ���ڸ� �Է¹��� ��
		scanf("%d", &temp);
		//printf("\n");
		number.push_back(temp);
		//printf("%d�� vector�� �ԷµǾ����ϴ�. \n",temp);
	}

	int maxium = 0;
	vector<int> cal;	//���ڸ��� ī��Ʈ�� ��� ����� ����� �迭
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (number[i] <= number[j]) {
				count++;
			}
		}
		if (count >= number[i] && number[i] > maxium) maxium = number[i];
	}


	printf("%d", maxium);
}