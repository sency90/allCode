#include <stdio.h>

int x = -1;	//구하고자 하는 값

void Homework(int num, int arr[]) {			//정수의 개수와 정수의 배열을 받아 x값을 구한다.
	for (int i = 0; i < num; i++) {
		int count = 0;		//현재의 원소보다 크거나 같은 숫자의 개슈
		if (arr[i] == num || arr[i] < num) {	//현재 원소값이 원소의 개수보다 작거나 같을 때
			for (int j = 0; j < num; j++) {
				if (arr[i] < arr[j] || arr[i] == arr[j]) {	//현재 원소보다 크거나 같으면 count에 1을 더해준다.
					count++;
				}
			}
		}
		if (count >= arr[i] && x < arr[i]) {	//count의 값이 현재 원소보다 크거나 같다. AND 현재 원소가 x에 저장된 값보다 크다.
			x = arr[i];		//x에 현재 원소값을 넣는다.
		}
	}
}

int main() {
	int n;	//정수의 개수
	int input[1000];	//n개 정수를 입력받을 배열

	scanf_s("%d", &n);	//정수의 개수를 입력받는다.
	if (n > 1000 || n < 1) {
		printf_s("n은 1이상 1,000이하의 정수입니다.");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &input[i]);	//n개의 정수를 입력받는다.
		if (input[i] > 10000 || input[i] < 0) {
			printf_s("0부터 10,000사이의 정수를 입력해주세요.");
			return 0;
		}
	}

	Homework(n,input);
	if (x == -1) {
		printf_s("조건을 만족하는 정수가 존재하지 않습니다.");
	}
	else {
		printf_s("%d", x);
	}
}