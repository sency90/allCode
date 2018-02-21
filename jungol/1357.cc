#include <stdio.h>
int a[16000002],b[16000002],tmp[16000002],x[4001][4];
inline void merge(int s,int m,int e) {
	int i=s,j=m+1,k=s;
	while(i<=m && j<=e) {
		if(b[i]<b[j]) tmp[k++]=b[i++];
		else tmp[k++]=b[j++];
	}
	while(i<=m) tmp[k++]=b[i++];
	while(j<=e) tmp[k++]=b[j++];

	for(i=s; i<=e; i++) b[i]=tmp[i];
}
inline void msort(int s,int e) {
	if(s==e) return;
	int m = (s+e)>>1;
	msort(s,m); msort(m+1,e);
	merge(s,m,e);
}
int main() {
	int n;
	register int i,j;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		for(j=0; j<4; j++) {
			scanf("%d",&x[i][j]);
		}
	}
	int cnt=0;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			a[cnt]=x[i][0]+x[j][1];
			b[cnt]=x[i][2]+x[j][3];
			cnt++;
		}
	}
	msort(0,cnt-1);
	int lbndidx,ubndidx,ans=0;
	for(i=0; i<cnt; i++) {
		int lo=0,hi=cnt-1;
		while(lo<=hi) {
			int mid=(lo+hi)>>1;
			if(b[mid]+a[i]<=0) lo=mid+1;
			else hi=mid-1;
		}
		if(b[lo-1]+a[i]!=0) continue;
		ubndidx=lo;

		lo=0; hi=cnt-1;
		while(lo<=hi) {
			int mid=(lo+hi)>>1;
			if(b[mid]+a[i]<0) lo=mid+1;
			else hi=mid-1;
		}
		if(b[lo]+a[i]!=0) continue;
		lbndidx=lo;

		ans+=ubndidx-lbndidx;
	}
	printf("%d",ans);
	return 0;
}
