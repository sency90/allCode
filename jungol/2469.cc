#include <stdio.h>
#include <algorithm>
using namespace std;
int fen[100002],n;
inline void update(int at,int by) {
	for(;at<=n;at+=at&-at) fen[at]+=by;
}
inline int query(int at) {
	int ret=0; for(;at;at-=at&-at) ret+=fen[at]; return ret;
}
int v[100002],o[100002],ans[100002];
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&v[i]);
	}
	sort(v+1,v+1+n);
	for(int i=1; i<=n; i++) {
		update(i,1);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&o[i]);
	}
	for(int i=n; i>=1; i--) {
		int lo=1,hi=n;
		while(lo<=hi) {
			int mid=(lo+hi)>>1;
			if(query(mid)<=o[i]) lo=mid+1;
			else hi=mid-1;
		}
		ans[i]=v[lo];
		update(lo,-1);
	}
	for(int i=1; i<=n; i++) printf("%d\n",ans[i]);
	return 0;
}
