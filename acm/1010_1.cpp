#include <stdio.h>
long long ret,i,m,n,t;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for(i=ret=1; i<=n; ) {
			ret *= m--;
			ret /= i++;
		}
		printf("%u\n", ret);
	}
}