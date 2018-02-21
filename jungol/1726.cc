#include <stdio.h>
#define r2 (r<<1)
#define m2 ((s+e)>>1)
inline int max(int x,int y) { return x>y?x:y; }
int tree[200001];
int update(int r,int s,int e,int idx,int x) {
	if(idx<s || e<idx) return 0;
	else if(s==e) return tree[r]=x;
	else return tree[r]=max(tree[r],max(update(r2,s,m2,idx,x),update(r2+1,m2+1,e,idx,x)));
}
int query(int r,int s,int e,int qs,int qe) {
	if(qe<s||e<qs) return 0;
	else if(qs<=s && e<=qe) return tree[r];
	else return max(query(r2,s,m2,qs,qe),query(r2+1,m2+1,e,qs,qe));
}
int main() {
	int n,m; scanf("%d%d",&n,&m);
	int lim = 1;
	while(n>lim) lim<<=1;
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d",&x);
		update(1,1,lim,i,x);
	}
	for(int i=0; i<m; i++) {
		int s,e;
		scanf("%d%d",&s,&e);
		printf("%d\n",query(1,1,lim,s,e));
	}
	return 0;
}
