#include<stdio.h>
#include<algorithm>
using namespace std;
int Check(int* num, int c) {
	int answer=0;
	sort(num,num+c);
	for (int i = 0; i < c; i++)	if (num[i] == c - i)	answer = num[i];
	return answer;
}
int main() {
	int count;
	scanf_s("%d", &count);//�Է��� ������ �� �Է�
	int *number = new int[count];//�Է��� ��ŭ �迭�� �����Ҵ��Ѵ�.
	for (int i = 0; i < count; i++)	scanf_s("%d", &number[i]);//������ �Է�
	printf_s("%d", Check(number,count));	//���ϴ� ���� ����Ѵ�.
	return 0;
}
