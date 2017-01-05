#include<stdio.h>
#include<algorithm>	//sort 를 사용하기 위해 헤더파일 선언
using namespace std;//sort를 사용하기 위해 스탠다드 네임스페이스 선언
int Check(int* num, int c) {
	int answer=0;	//결과값이 없다면 0을 출력하도록 초기화
	sort(num,num+c);//배열 정렬
	for (int i = 0; i < c; i++)	if (num[i] == c - i)	answer = num[i];
	return answer;	//배열 크기 - 인덱스가 본인 보다 큰거나 같은 원소의 수이며
}					//정렬된 배열에서 점점 큰 수를 확인하므로 해당 수를 answer변수에 덮어쓴다.
int main() {
	int count;
	scanf_s("%d", &count);//입력할 데이터 수 입력
	int *number = new int[count];//입력할 만큼 배열을 동적할당한다.
	for (int i = 0; i < count; i++)	scanf_s("%d", &number[i]);//데이터 입력
	printf_s("%d", Check(number,count));	//원하는 값을 출력한다.
	return 0;
}