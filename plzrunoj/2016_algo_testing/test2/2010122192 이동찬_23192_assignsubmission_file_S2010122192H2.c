#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int num[MAX];
//O(nlogn)
int main(){
	
	int n, max=0;
	scanf("%d", &n);

	for(int i=0; i<n; i++) scanf("%d", &num[i]);

	sort(num, num+n);

	for(int i=0; i<n; i++){
		if(n-i>=num[i] && num[i]>max) max=num[i]; 
	}
	cout<<max<<endl;
	return 0;
}

// O(n)