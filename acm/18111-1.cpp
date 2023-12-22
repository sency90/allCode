#include <stdio.h>
int v[501][501];
int min(int x, int y) { return x<y?x:y; }
int max(int x, int y) { return x>y?x:y; }
const int inf = 0x3f3f3f3f;
int n,m,B;
int calc(int h, int b) {
	int ret=0,i,j;
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			if(v[i][j]==h) continue;
			if(v[i][j]>h) {
				ret+=(v[i][j]-h)*2;
				b+=(v[i][j]-h);
			}
			else {
				ret+=(h-v[i][j]);
				b-=(h-v[i][j]);
			}
		}
	}
	B = b;
	if(b>=0) return ret;
	else return inf;
}
int main() {
	freopen("input.txt", "r", stdin);
	int b,mn=inf,mx=0,i,j;
	scanf("%d%d%d",&n,&m,&b);
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			scanf("%d", &v[i][j]);
			mn = min(v[i][j], mn);
			mx = max(v[i][j], mx);
		}
	}
	int ans_t=inf,ans_h=mn,h,t;
	for(h=mn; h<=mx; h++) {
		t = calc(h, b);
		if(ans_t >= t) {
			ans_t = t;
			ans_h = h;
		}
		printf("h:%d -> t:%d, ans_t:%d, ans_h:%d, inven:%d\n", h, t, ans_t, ans_h, B);
	}
	printf("%d %d\n", ans_t, ans_h);
	return 0;
}
