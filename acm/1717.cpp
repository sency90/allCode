#include <stdio.h>
int p[1000001];
int find(int x) {
	if(x == p[x]) return x;
	else return p[x] = find(p[x]);
}
void uni(int x, int y) {
	p[find(y)] = find(x);
}

int main() {
	int n, m, op, a, b;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		p[i] = i;
	}
	for(int i=0; i<m; i++) {
		scanf("%d %d %d", &op, &a, &b);
		if(op==0) {
			uni(a,b);
		} else {
			if(find(a) == find(b)) puts("YES");
			else puts("NO");
		}
	}
    return 0;
}
