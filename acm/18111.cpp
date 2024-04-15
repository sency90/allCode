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

	for(i=1; i<=256; i++) cnt[i] += cnt[i-1];
	for(i=lim-1; i>=0; i--) sv[--cnt[v[i]]] = v[i];
	v[0] = 0;
	for(i=0; i<lim; i++) {
		v[i+1] = sv[i];
		v[i+1] += v[i];
	}

	sv[lim] = inf; v[lim+1] = v[lim];
	int mem=0, ans_t=inf, ans_h, h;
	for(h=mn; h<=mx; h++) {
		int lo=mem, hi=lim, ans_lb, ans_ub;
		while(lo <= hi) {
			int mid = (lo+hi)/2;
			if(sv[mid]>=h) {
				hi = mid-1;
				ans_lb = mid;
			}
			else lo = mid+1;
		}
		lo=ans_lb, hi=lim;
		while(lo <= hi) {
			int mid = (lo+hi)/2;
			if(sv[mid]>h) {
				hi = mid-1;
				ans_ub = mid;
			}
			else lo = mid+1;
		}
		int L = h*ans_lb-v[ans_lb];
		int R = v[lim]-v[ans_ub]-h*(lim-ans_ub);
		int t = L + 2*R;
		if(b-L+R>=0 && ans_t >= t) {
			ans_t = t;
			ans_h = h;
		}
		mem = ans_ub;
	}

	printf("%d %d\n", ans_t, ans_h);
	return 0;
}
