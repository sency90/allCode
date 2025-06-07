#include<stdio.h>
#include<vector>

using namespace std;

int main() {

	vector<int> number;

	int n = 0;
	scanf("%d", &n);			//입력받을 숫자의 개수 설정
//	printf("\n");

	//vector에 숫자들 배열로 저장
	for (int i = 0; i < n; i++) {
		int temp = 0;		//임의의 숫자를 입력받을 곳
		scanf("%d", &temp);
		//printf("\n");
		number.push_back(temp);
		//printf("%d가 vector에 입력되었습니다. \n",temp);
	}

	int maxium = 0;
	vector<int> cal;	//숫자마다 카운트가 몇개가 됬는지 계산할 배열
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (number[i] <= number[j]) {
				count++;
			}
		}
		if (count >= number[i] && number[i] > maxium) maxium = number[i];
	}


	printf("%d", maxium);
}