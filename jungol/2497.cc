#include <stdio.h>
int fen[100001],n;
const int inf=0x3f3f3f3f;
inline int max(int x,int y) { return x>y?x:y; }
inline void update(int i,int by) {
	for(; i<=n; i+=i&-i) fen[i]+=by;
}
inline int query(int i) {
	int ret = 0;
	for(;i;i-=i&-i) ret+=fen[i];
	return ret;
}
int main() {
	int k; scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++) {
		int x; scanf("%d",&x);
		update(i,x);
	}
	int mx=-inf;
	for(int i=k; i<=n; i++) {
		mx = max(mx,query(i)-query(i-k));
	}
	printf("%d",mx);
	return 0;
}
