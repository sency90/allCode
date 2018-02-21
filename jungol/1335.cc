#include <stdio.h>
int v[129][129],o[129][129],cnt,bluecnt;
inline int g(int sx,int sy,int ex,int ey) {
	return (ex-sx+1)*(ey-sy+1);
}
inline int s(int sx,int sy,int ex,int ey) {
	return v[ex][ey]-v[sx-1][ey]-v[ex][sy-1]+v[sx-1][sy-1];
}
void solve(int sx,int sy,int ex,int ey) {
	if(sx==ex) {
		if(s(sx,sy,ex,ey)==1) cnt++;
		return;
	}
	int mx=(sx+ex)>>1,my=(sy+ey)>>1;
	if(s(sx,sy,mx,my)==g(sx,sy,mx,my)) cnt++;
	else solve(sx,sy,mx,my);
	if(s(sx,my+1,mx,ey)==g(sx,my+1,mx,ey)) cnt++;
	else solve(sx,my+1,mx,ey);
	if(s(mx+1,sy,ex,my)==g(mx+1,sy,ex,my)) cnt++;
	else solve(mx+1,sy,ex,my);
	if(s(mx+1,my+1,ex,ey)==g(mx+1,my+1,ex,ey)) cnt++;
	else solve(mx+1,my+1,ex,ey);
}

int main() {
	int n; scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%d",&o[i][j]);
			v[i][j]=o[i][j];
			v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
		}
	}
	solve(1,1,n,n);
	bluecnt=cnt;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			o[i][j]^=1;
			v[i][j]=o[i][j];
			v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
		}
	}

	cnt=0;
	solve(1,1,n,n);

	printf("%d\n%d\n",cnt, bluecnt);
	return 0;
}
