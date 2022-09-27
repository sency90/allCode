#include <stdio.h>
int max(int x, int y) {
	return x>y?x:y;
}
int x[3], y[3];
int repos(int a, int m) {
	if(a>m) return a-m;
	else return m-a;
}
int main() {
	int n = 0;
	scanf("%d", &n);
	n*=100;
	for(int i=0; i<3; i++) {
		scanf("%d%d",&x[i],&y[i]);
		x[i]*=100;
		y[i]*=100;
	}
	int m = 0;
	if(x[0]!=y[0]) {
		m = (x[0]+y[0])/2;
		for(int i=1; i<3; i++) {
			x[i] = repos(x[i], m);
			y[i] = repos(y[i], m);
		}
		n = max(n-m, m);
	}

	if(x[1]!=y[1]) {
		m = (x[1]+y[1])/2;
		x[2] = repos(x[2], m);
		y[2] = repos(y[2], m);
		n = max(n-m, m);
	}

	if(x[2]!=y[2]) {
		m = (x[2]+y[2])/2;
		n = max(n-m, m);
	}

	printf("%.1lf\n", (double)n/100.0);
	return 0;
}
