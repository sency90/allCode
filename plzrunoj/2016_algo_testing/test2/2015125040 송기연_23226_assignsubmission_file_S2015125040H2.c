#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int main()
{
	int num;
	int iset[1000];
	int numberofset[1000] = {0};
	int max =0;

	cout << "Num : ";
	cin >> num;

	cout << "Numbers : ";
	for (int i = 0; i < num; i++) cin >> iset[i]; //�Է�
	
	for (int i = 0; i < num; i++) { //�Է¹��� ���ڵ��� ���ǿ� �´� ���ڵ��� ������ ���� ��Ʈ�� �迭�� ���� ����
		for (int j = 0; j < num; j++) {
			if (iset[i] <= iset[j]) { numberofset[i]++; }
		}
	}

	for (int i = 0; i < num; i++) { //���� ���� Ƚ���� ������ ���ڿ� ������ ���ϰ� �ִ밪���� ũ�ٸ� �ִ밪 ����
		if (numberofset[i] >= iset[i]) {
			if (iset[i] >= max) {
				max = iset[i];
			}
		}
	}
	
	cout << "��� : " << max << endl; // �ִ밪���
	return 0;
}