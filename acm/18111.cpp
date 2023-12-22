#include <stdio.h>
#include <algorithm>
using namespace std;
int v[501*501], sv[501*501], cnt[257];
int min(int x, int y) { return x<y?x:y; }
int max(int x, int y) { return x>y?x:y; }
const int inf = 0x3f3f3f3f;
int n,m;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int b,mn=inf,mx=0,i,j;
	scanf("%d%d%d",&n,&m,&b);
	int lim = n*m;
	for(i=0; i<lim; i++) {
		scanf("%d", &v[i]);
		cnt[v[i]]++;
		mn = min(mn, v[i]);
		mx = max(mx, v[i]);
	}

	for(i=0; i<=256; i++) cnt[i] += cnt[i-1];
	for(i=lim-1; i>=0; i--) sv[--cnt[v[i]]] = v[i];
	v[0] = 0;
	for(i=0; i<lim; i++) {
		v[i+1] = sv[i];
		v[i+1] += v[i];
	}

	//sv: [0,lim-1], v: [1,lim]
	int ans_t=inf, ans_h=mn;
	for(int h=mn; h<=mx; h++) {
		int lo = std::lower_bound(sv, sv+lim, h)-sv;
		int hi = std::upper_bound(sv, sv+lim, h)-sv;

		//[0,lo-1], [hi,lim-1]
		//[1,lo], [hi+1,lim]
		int L = (h*lo-(v[lo]-v[0]));
		int R = (v[lim]-v[hi])-h*(lim-hi);
		int t = L+2*R;
		if(b-L+R>=0 && ans_t>=t) {
			ans_t = t;
			ans_h = h;
		}
	}
	printf("%d %d\n", ans_t, ans_h);
	return 0;
}
