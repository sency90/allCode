#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int n, arr[1000];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n, greater<int>());
	for (int i = 0; i < n; i++)
		if (arr[i] <= i+1){
			printf("%d\n", arr[i]);
			break;
		}
	return 0;
}