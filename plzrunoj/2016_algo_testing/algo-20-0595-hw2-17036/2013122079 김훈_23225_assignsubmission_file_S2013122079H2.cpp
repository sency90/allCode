#include<stdio.h>
#include<algorithm>	//sort �� ����ϱ� ���� ������� ����
using namespace std;//sort�� ����ϱ� ���� ���Ĵٵ� ���ӽ����̽� ����
int Check(int* num, int c) {
	int answer=0;	//������� ���ٸ� 0�� ����ϵ��� �ʱ�ȭ
	sort(num,num+c);//�迭 ����
	for (int i = 0; i < c; i++)	if (num[i] == c - i)	answer = num[i];
	return answer;	//�迭 ũ�� - �ε����� ���� ���� ū�ų� ���� ������ ���̸�
}					//���ĵ� �迭���� ���� ū ���� Ȯ���ϹǷ� �ش� ���� answer������ �����.
int main() {
	int count;
	scanf_s("%d", &count);//�Է��� ������ �� �Է�
	int *number = new int[count];//�Է��� ��ŭ �迭�� �����Ҵ��Ѵ�.
	for (int i = 0; i < count; i++)	scanf_s("%d", &number[i]);//������ �Է�
	printf_s("%d", Check(number,count));	//���ϴ� ���� ����Ѵ�.
	return 0;
}