// 0부터 10,000 사이의 정수 n개가 주어진다. n은 1 이상 1,000 이하이다. 
// 이 중 한 숫자 x를 생각해보자.
// n개의 숫자 중에서 x보다 같거나 큰 숫자가 x번 이상 나올 수 있다.
// 이 조건을 만족하는 x 중 가장 큰 수를 출력하는 프로그램을 작성하시오.
// 예를 들어, 숫자가 8, 4, 5, 3, 10이라고 한다면

// - 8보다 같거나 큰 수는 8, 10. 총 2개
// - 4보다 같거나 큰 수는  8, 4, 5, 10 총 4개
// - 5보다 같거나 큰 수는 8, 5, 10 총 3개
// - 3보다 같거나 큰 수는 8, 4, 5, 3, 10 총 5개
// - 10보다 같거나 큰 수는 10 총 1개

// 조건을 만족하는 수는 4와 3이며, 이 중 가장 큰 4가 답이다.

#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

void method(vector<int> arr);

int main()
{
	
	int NumA = 0, tmp;
	
	scanf("%d\n", &NumA);
	vector<int> arrTemp;
	for (int z = 0; z < NumA; z++)
	{
		scanf("%d ",&tmp);
		arrTemp.push_back(tmp);
	}
	method(arrTemp);
	
	return 0;
}

void method(vector<int> arr)
{
	int cnt=0, target=0;
	int Max=0, index=0; 

	for (int i = 0; i < arr.size(); i++)
	{
		target = arr.at(i);
		for (int j = 0; j < arr.size(); j++)
		{
			if (target <= arr.at(j)) cnt++;
		}
		if (cnt >= target){
			if (index < arr.at(i)){
				Max = cnt;
				index = arr.at(i);
			}
		}
		cnt = 0;
	}

	printf("%d\n", index);
}