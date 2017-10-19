#include <stdio.h>
typedef long long ll;
ll v[100001],c,tmp[100001];
void merge(int s, int m, int e) {
    int i=s,j=m+1,k=s;
    while(i<=m && j<=e) {
        if(v[i]<v[j]) tmp[k++]=v[i++];
        else tmp[k++]=v[j++];
    }
    while(i<=m) tmp[k++] = v[i++];
    while(j<=e) tmp[k++] = v[j++];
    for(int i=s; i<=e; i++) v[i]=tmp[i];
}
void msort(int s, int e) {
    if(s==e) return;
    int m=(s+e)>>1;
    msort(s,m); msort(m+1,e);
    merge(s,m,e);
}
ll spow(ll x,int y) {
	if(y==0) return 1LL;
	ll ret = spow(x,y/2);
	if(y&1) return ret*ret*x;
	else return ret*ret;
}
const ll lim = 1e10;
int main() {
	int sz=0;
	for(int i=0; i<15; i++) {
		for(int j=0; j<20; j++) {
			for(int k=0; k<30; k++) {
				ll res = spow(5,i) * spow(3,j) * (1LL<<k);
				if(res>=lim || res<0LL) continue;
				else v[sz++]=res;
			}
		}
	}
	msort(0,sz-1);
	while(true) {
		int x; scanf("%d",&x);
		if(x==0) return 0;
		printf("%lld\n",v[x-1]);
	}
	return 0;
}
