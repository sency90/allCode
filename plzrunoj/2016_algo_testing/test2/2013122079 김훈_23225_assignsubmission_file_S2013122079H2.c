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
	scanf_s("%d", &count);//입력할 데이터 수 입력
	int *number = new int[count];//입력할 만큼 배열을 동적할당한다.
	for (int i = 0; i < count; i++)	scanf_s("%d", &number[i]);//데이터 입력
	printf_s("%d", Check(number,count));	//원하는 값을 출력한다.
	return 0;
}
