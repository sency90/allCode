#include <cstdio>
using namespace std;
int a[1000001];
int main() {
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	int b,c; scanf("%d%d",&b,&c);
	long long cnt=0;
	for(int i=0; i<n; i++) {
		a[i]-=b;
		cnt++;
	}
	for(int i=0; i<n; i++) {
		if(a[i]<=0) continue;
		cnt += (a[i]+(c-1))/c;
	}
	printf("%lld\n", cnt);
	return 0;
}
