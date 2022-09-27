#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int x, cnt, v[100001];
int main() {
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}
	scanf("%d", &x);
	sort(v, v+n);

	for(int i=0,j=n-1; i<n && j>=0; ) {
		if(v[i]+v[j]<x) i++;
		else if(v[i]+v[j]>x) j--;
		else cnt++, j--;
	}
	printf("%d\n", cnt/2);
	return 0;
}
