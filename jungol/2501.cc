#include <stdio.h>
int v[100001],cnt[4],g[4][4],o[6][3];
inline void init() {
	o[0][0]=1; o[0][1]=2; o[0][2]=3;
	o[1][0]=1; o[1][1]=3; o[1][2]=2;
	o[2][0]=2; o[2][1]=1; o[2][2]=3;
	o[3][0]=2; o[3][1]=3; o[3][2]=1;
	o[4][0]=3; o[4][1]=1; o[4][2]=2;
	o[5][0]=3; o[5][1]=2; o[5][2]=1;
}
inline void ginit() {
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			g[i][j]=0;
		}
	}
}
inline int min(int x,int y) { return x<y?x:y; }
inline int max(int x,int y) { return x>y?x:y; }
int main() {
	init();
	int n; scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&v[i]);
		cnt[v[i]]++;
	}
	int ans=0x3f3f3f3f;
	for(int z=0; z<6; z++) {
		int k=0,tcnt=0;
		ginit();
		int lim = cnt[o[z][k]];
		for(int i=0; i<n; i++) {
			if(i<lim) g[o[z][k]][v[i]]++;
			else {
				g[o[z][++k]][v[i]]++;
				lim+=cnt[o[z][k]];
			}
		}

		for(int i=1; i<=3; i++) {
			for(int j=1; j<=3; j++) {
				if(i==j) continue;
				int mn=min(g[i][j],g[j][i]);
				g[i][j]-=mn;
				g[j][i]-=mn;
				tcnt+=mn;
			}
		}

		int mx=0;
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=3; j++) {
				if(i==j) continue;
				mx = max(mx,g[i][j]);
			}
		}
		tcnt+=mx*2;
		ans = min(ans,tcnt);
	}
	printf("%d",ans);
	return 0;
}
