#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> ans;
int a[19];
void make_zero(int l, int r) {
	for(int i=l; i<=r; i++) {
		if(a[i]) ans.push_back(pii(i+1,i+1));
	}
}
void build(int l, int r) {
	if(l==r) {
		ans.push_back(pii(l+1,r+1));
		return;
	}
	build(l,r-1);
	for(int i=r-2; i>=l; i--) {
		ans.push_back(pii(l+1,i+1));
		build(l,i);
	}
	ans.push_back(pii(l+1,r+1));
}
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	int mx=-1, mxbit=0;
	for(int s=0; s<(1<<n); s++) {
		int tmp = 0;
		for(int l=0; l<n; l++) {
			if(s&(1<<l)) {
				int r = l;
				while(r+1<n && s&(1<<(r+1))) r++;
				tmp += (r-l+1)*(r-l+1);
				l = r;
			}
			else tmp += a[l];
		}
		if(tmp > mx) {
			mx = tmp;
			mxbit = s;
		}
	}
	for(int l=0; l<n; l++) {
		if(mxbit&(1<<l)) {
			int r = l;
			while(r+1<n && mxbit&(1<<(r+1))) r++;
			make_zero(l,r);
			build(l,r);
			l = r;
		}
	}
	printf("%d %d\n", mx, (int)ans.size());
	for(int i=0; i<ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
