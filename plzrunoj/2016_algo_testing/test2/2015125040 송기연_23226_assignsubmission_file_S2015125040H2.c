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
	for (int i = 0; i < num; i++) cin >> iset[i]; //입력
	
	for (int i = 0; i < num; i++) { //입력받은 숫자들중 조건에 맞는 숫자들의 개수를 새어 인트형 배열로 새로 저장
		for (int j = 0; j < num; j++) {
			if (iset[i] <= iset[j]) { numberofset[i]++; }
		}
	}

	for (int i = 0; i < num; i++) { //만일 나온 횟수가 본인의 숫자와 같은지 비교하고 최대값보다 크다면 최대값 변경
		if (numberofset[i] >= iset[i]) {
			if (iset[i] >= max) {
				max = iset[i];
			}
		}
	}
	
	cout << "결과 : " << max << endl; // 최대값출력
	return 0;
}