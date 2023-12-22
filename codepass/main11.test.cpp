#include <stdio.h>
int combi(int n, int r) {
	if(n==r || r==0) return 1;
	return combi(n-1,r-1) + combi(n-1,r);
}
int main() {
	for(int i=1; i<15; i++) {
		int x = combi(i, i/2);
		printf("combi(%d, %d) = %d\n", i, i/2, x);
	}
	return 0;
}
