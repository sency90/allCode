#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
	vector<int> v; // ���� ����. 
	int input,count,i; // input: ���� ���� count: �Է� ��. 
	int point; //���������̹Ƿ� ���� ���鼭 ����. �̰��� ����� ���ִ� ����.
	bool IsTrue=false; // �Ǵܺ���.
	point=1;// ��ó���� 1�� �ʱ�ȭ.
	scanf("%d",&input); // �Է�.

	for(i=0;i<input;i++){
		scanf("%d",&count); // ���� �Է�.
		v.push_back(count); // ���� ������ ����.
	}

	sort(v.begin(),v.end(),std::greater<int>()); // �������� ����.
	
	for(i=0;i<input;i++){ // ���� ���� ��ŭ �ݺ�.
		if(point==v[i]){ // x�� x�� ������.
			break;
		}
		else if(i<input-1){
			if(point<v[i] && point>v[i+1]){ // x�� �Է� �� ���̿� ������.
				IsTrue=true;
				break;
			}
			if(point==v[i+1]){ // x�� ���� ���̶� ������.
				IsTrue=true;
				break;
			}
		}
		else if(point<v[i] && point>0){// x�� 0�� �Ǹ������� ���̿� ������.
			IsTrue=true;
			break;
		}
		point++; // x�� ����.
	}

	if(input-i==0 && v[0]>=v[i-1]){ // ū���� �ƿ� ������.. 
		printf("%d\n",v[0]);
	}
	else if(IsTrue==false){// ū�� ������ �ڱ� �Է°� �ڽ��� �����ϰ� �̻��϶�.
		printf("%d\n",v[i]); // �ڱ� �ڽ� ���.
	}
	else if(IsTrue==true){ // ���� ��� �� true�� ��ȯ�� ������ ���� ��� ������� ���� ���.
		printf("%d\n",point);
	}
	return 0;
}