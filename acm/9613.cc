#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
int v[101];
int gcd(int b, int s) {
	if(s==0) return b;
	else return gcd(s, b%s);
}
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int n; scanf("%d", &n);
		int i,j;
		for(i=0; i<n; i++) {
			scanf("%d", &v[i]);
		}
		if(n==1) printf("%d\n", v[0]);
		else {
			ll sum=0;
			for(i=0; i<n; i++) {
				for(j=i+1; j<n; j++) {
					sum += gcd(v[i],v[j]);
				}
			}

			printf("%lld\n", sum);
		}
	}
	return 0;
}
