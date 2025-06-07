#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
	vector<int> v; // 벡터 선언. 
	int input,count,i; // input: 수의 개수 count: 입력 수. 
	int point; //내림차순이므로 점점 가면서 증가. 이것이 몇개인지 세주는 역할.
	bool IsTrue=false; // 판단변수.
	point=1;// 맨처음은 1로 초기화.
	scanf("%d",&input); // 입력.

	for(i=0;i<input;i++){
		scanf("%d",&count); // 숫자 입력.
		v.push_back(count); // 벡터 변수에 삽입.
	}

	sort(v.begin(),v.end(),std::greater<int>()); // 내림차순 정렬.
	
	for(i=0;i<input;i++){ // 원소 개수 만큼 반복.
		if(point==v[i]){ // x가 x랑 같을때.
			break;
		}
		else if(i<input-1){
			if(point<v[i] && point>v[i+1]){ // x가 입력 값 사이에 있을때.
				IsTrue=true;
				break;
			}
			if(point==v[i+1]){ // x가 다음 값이랑 같을때.
				IsTrue=true;
				break;
			}
		}
		else if(point<v[i] && point>0){// x가 0과 맨마지막에 사이에 있을때.
			IsTrue=true;
			break;
		}
		point++; // x값 증가.
	}

	if(input-i==0 && v[0]>=v[i-1]){ // 큰수가 아에 없을때.. 
		printf("%d\n",v[0]);
	}
	else if(IsTrue==false){// 큰수 개수가 자기 입력값 자신을 포함하고 이상일때.
		printf("%d\n",v[i]); // 자기 자신 출력.
	}
	else if(IsTrue==true){ // 위의 경우 즉 true로 전환될 조건이 맞을 경우 현재까지 개수 출력.
		printf("%d\n",point);
	}
	return 0;
}