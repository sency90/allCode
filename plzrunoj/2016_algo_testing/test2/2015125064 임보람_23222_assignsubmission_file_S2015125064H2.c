#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int find(int array[], int n) {
	int *count = new int[n];	//x보다 같거나 큰 숫자가 몇 번 나오는지 저장하는 배열
	int i = 0, j = 0, temp = 0, t = -1;

	//값을 오름차순으로 정렬 - 선택정렬 이용
	for (i = 0; i < n - 1; i++)
	{
		int index = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[index] > array[j])
			{
				index = j;
			}
		}
		temp = array[index];
		array[index] = array[i];
		array[i] = temp;
	}
	
	for (i = 0; i < n; i++) {
		//같거나 큰 수 세기
		count[i] = n - i;
		
		if (count[i] >= array[i]) {
		//x보다 같거나 큰 숫자가 x번 이상 나오는 경우
			if (count[i] >= t) {
				t = array[i];	//같거나 큰 숫자의 개수가 가장 많은 x
			}
		}
	}
	return t;
}

void main() {
	int n;
	int result;

	while (true) {
		//데이터 개수 입력
		scanf("%d", &n);
	
		if (n > 1000 || n < 1) {
			printf("1~1000 사이 수 입력\n");
			continue;
		}
		break;
	}
	int *array = new int[n];

	while (true) {
		//데이터 입력
		int rp = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &array[i]);
			
			if (array[i] < 0 || array[i]>10000) {
				printf("0~10000 사이 수 입력\n");
				rp = -1;
			}
		}
		if (rp != 0) {
			continue;
		}
		else {
			break;
		}
	}
	
	result = find(array, n);

	printf("%d\n", result);
}