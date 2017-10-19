#include <stdio.h>
struct Info{
	int s,e;
	Info(){}
	Info(int s,int e):s(s),e(e){}
	inline bool operator<(const Info &rhs) const { return s<rhs.s; }
	Info& operator=(const Info &rhs) {
		this->s=rhs.s;
		this->e=rhs.e;
		return *this;
	}
};
Info v[2000001], tmp[2000001];
template <typename T> inline void merge(int s,int m,int e) {
	int i=s,j=m+1,k=s;
	while(i<=m && j<=e) {
		if(v[i]<v[j]) tmp[k++]=v[i++];
		else tmp[k++]=v[j++];
	}
	while(i<=m) tmp[k++]=v[i++];
	while(j<=e) tmp[k++]=v[j++];
	for(int i=s; i<=e; i++) v[i]=tmp[i];
}
template <typename T> inline void msort(int s,int e) {
	if(s==e) return;
	int m = (s+e)>>1;
	msort<T>(s,m); msort<T>(m+1,e);
	merge<T>(s,m,e);
}
int whv[1000001],cnt=0, chk[1000001];
inline void dfs(int x, int r) {
	bool ch=false;
	for(int i=whv[x]; v[i].s==x; i++) {
		if(v[i].e^r) {
			dfs(v[i].e,x);
			ch|=!chk[v[i].e];
		}
	}
	if(ch) chk[x]=true,cnt++;
}
int main() {
	int n;
	scanf("%d",&n); n--;
	for(int i=0; i<n; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		v[i]=Info(x,y);
		v[i+n]=Info(y,x);
	}
	n<<=1;
	msort<int>(0,n-1);

	whv[v[0].s]=0;
	for(int i=1; i<n; i++) if(v[i-1].s != v[i].s) whv[v[i].s]=i;
	dfs(1,0);
	printf("%d",cnt);
	return 0;
}
