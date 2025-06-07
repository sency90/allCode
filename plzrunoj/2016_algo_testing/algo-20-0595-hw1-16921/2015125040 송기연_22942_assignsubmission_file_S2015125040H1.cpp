#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

bool IsSameCombination(char** L1, char** L2, int range) {	//�� �迭�� ������ ������ �Ǻ��ϴ� �Լ�
	int checklist[1000] = { 0 };

	for (int i = 0; i < range; i++) {
		for (int j = 0; j < range; j++) {
			if ((strcmp(L1[i],L2[j]) == 0) && (checklist[j] != 1)) {
				checklist[j] = 1;
				break;
			}
		}
	}
	
	for (int i = 0; i < range; i++) {
		if (checklist[i] == 0) {
			return false;
		}
	}
	return true;
}

char** substring(char** str, int start, int end) { //�迭�� �κ��� ���� ���� ����� �Լ�
	char** sub = new char*[end - start];
	int count = 0;
	int i;

	for (i = start; i < end; i++) {
		sub[count] = new char[1000];

		strcpy(sub[count++], str[i]);

	}

	return sub;
}


char** searchMidle(char** first, char** last, int node) { //��Ʈ�� ã�� �� Ʈ���� ��Ʈ�� �κ��� ã�� �� + ��Ʈ + �� ������ �����ϴ� �Լ� 
	int leftcount = 0;
	bool isLeft = false;

	char** result = new char*[node];
	char** Lefttemp;
	char** Righttemp;

	if (node == 1) { //��尡 �ϳ��̸� �״�� ��ȯ
		return first;
	}

	while (!(isLeft)) { //��Ʈ���� ã�������� Ž��
		leftcount++;
		isLeft = IsSameCombination(substring(first, 1, leftcount + 1), substring(last, 0, leftcount), leftcount);

	}

	Lefttemp = searchMidle(substring(first, 1, 1 + leftcount), substring(last, 0, leftcount), leftcount);	//���� Ʈ�� �ϼ�
	Righttemp = searchMidle(substring(first, 1 + leftcount, node), substring(last, leftcount, node), node - leftcount - 1); //������ Ʈ�� �ϼ�


	for (int i = 0; i < leftcount; i++) { //����Ʈ�� ��ġ��
		result[i] = new char[1000];
		strcpy(result[i], Lefttemp[i]);
	}

	result[leftcount] = new char[1000]; //���
	strcpy(result[leftcount], first[0]);

	for (int i = leftcount + 1; i < node; i++) { //������ Ʈ�� ��ġ��
		result[i] = new char[1000];
		strcpy(result[i], Righttemp[i-leftcount-1]);
	}

	return result;
}


int main() {
	int node; //���
	char firstSearch[2000]; //�Է¹ޱ�� �迭
	char lastSearch[2000];
	
	char** firstTrimNode = new char*[1000]; //���� ���� �迭(���ڰ� 10�� �Ѿ �� ���̰� �ΰ��ΰ͵� �Է� �ޱ� ���ؼ� 2���� �迭�� ���)
	char** lastTrimNode = new char*[1000];

	char** resultMidle; //���

	cout << "Node ���� : ";
	scanf("%i", &node);
	printf("���� ��ȸ : ");
	scanf("\n");
	fgets(firstSearch, sizeof(firstSearch), stdin);
	cout << "���� ��ȸ : ";
	fgets(lastSearch, sizeof(firstSearch), stdin);

	int count = 0;
	char *ptr;
	ptr = strtok(firstSearch, "\t \n");
	while (ptr != NULL) { //��������
		firstTrimNode[count] = new char[1000];
		strcpy(firstTrimNode[count], ptr);
		strcat(firstTrimNode[count], "\0");
		ptr = strtok(NULL, "\t \n");
		count++;
	}

	int count2 = 0;
	char *ptr2;
	ptr2 = strtok(lastSearch, "\t \n");
	while (ptr2 != NULL) { //��������
		lastTrimNode[count2] = new char[1000];
		strcpy(lastTrimNode[count2], ptr2);
		strcat(lastTrimNode[count2], "\0");
		ptr2 = strtok(NULL, "\t \n");
		count2++;
	}

	resultMidle = searchMidle(firstTrimNode, lastTrimNode, node); //���� ��ȸ Ž��

	cout << "----<���>----\n���� ��ȸ : ";
	for (int i = 0; i < node; i++) cout << resultMidle[i] << " ";
	cout << endl;
	return 0;
}