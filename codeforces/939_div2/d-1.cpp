#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> ans;
int a[19];
void mk_zero(int l, int r) {
	for(int i=l; i<=r; i++) {
		if(a[i]) ans.emplace_back(i+1,i+1);
	}
}
void build(int l, int r) {
	if(l==r) {
		ans.emplace_back(l+1,l+1);
		return;
	}
	build(l,r-1);
	for(int i=r-2; i>=l; i--) {
		ans.emplace_back(l+1,i+1); //mk_zero(l,i);
		build(l,i);
	}
	ans.emplace_back(l+1,r+1);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	int mx=0, mxbit=0;
	for(int b=0; b<(1<<n); b++) {
		int l=0,r=0;
		int tmp=0;
		for(int i=0; i<n; i++) {
			if(b & (1<<i)) {
				l=r=i;
				while(r+1<n && (b & (1<<(r+1)))) r++;
				tmp += (r-l+1)*(r-l+1);
				i=r;
			}
			else tmp += a[i];
		}
		if(mx < tmp) {
			mx = tmp;
			mxbit = b;
		}
	}
	int l=0,r=0;
	for(int i=0; i<n; i++) {
		if(mxbit & (1<<i)) {
			l=r=i;
			while(r+1<n && (mxbit & (1<<(r+1)))) r++;
			mk_zero(l,r);
			build(l,r);
			i=r;
		}
	}
	printf("%d %d\n", mx, (int)ans.size());
	for(int i=0; i<ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
