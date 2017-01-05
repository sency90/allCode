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
