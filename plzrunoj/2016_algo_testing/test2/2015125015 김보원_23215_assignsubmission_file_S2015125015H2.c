#include<stdio.h>

using namespace std;

//답을 찾아내는 함수
int sort(int n, int Array_1[]) {
	int i, j, temp;
	int k, l, p; 
	int count = 0;
	int result;
	int* Array_2 = new int[n];
	int* Array_3 = new int[n];

	//입력값 정렬
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (Array_1[j] > Array_1[j + 1]) {
				temp = Array_1[j];
				Array_1[j] = Array_1[j + 1];
				Array_1[j + 1] = temp;
			}
		}
	}

	count = n;
	
	//자기보다 큰 값이 몇개있는지 count 
	for (k = 0; k < n; k++) {
		Array_2[k] = count;
		count--;
	}

	//조건에 맞는것 표시 
	for (l = 0; l < n; l++) {
		if (Array_1[l] <= Array_2[l]) {
			Array_3[l] = 1;
		}
	}
	
	//해당 조건 중 가장 큰값에 해당하는 것 찾기 
	for (p = 0; p < n; p++) {
		if (Array_3[p] == 1) {
			result = p;
			}
	}

	//결과값 출력
	printf("%d\n", Array_1[result]);

	return 0;
}

//main()함수 
int main() {
	int n;
	scanf("%d", &n);
	if (n < 1 || n > 1000) {
		printf( "조건 성립 안함. 프로그램 종료 (1~1000)" );
		return 0;
	}
	int* Array_1 = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &Array_1[i]);
	}

	for (int i = 0; i < n; i++) {
		if ((Array_1[i] > 10000) || (Array_1[i] < 0)) {
			printf ("조건 성립 안함. 프로그램 종료(0~10000)" );
			return 0;
		}
	}

	//결과값 찾는 함수 실행
	sort(n, Array_1);

	return 0;
}