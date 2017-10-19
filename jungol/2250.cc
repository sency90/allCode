#include <stdio.h>
#include <deque>
using namespace std;
int v[5][5], ori[5][5];
int mn = 8;
int ans[7][3];
inline int cntWrong() {
	int cnt=0;
	for(int i=1; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			if(v[i][j]!=ori[i][j]) cnt++;
		}
	}
	return cnt;
}

inline int f(int x) {
	if(x>=5) return x-4;
	else return x;
}

inline void go(int t,int rc,int n) {
	int tmp[5];
	if(t==1) {
		for(int i=1; i<=4; i++) tmp[f(i+n)]=v[rc][i];
		for(int i=1; i<=4; i++) v[rc][i]=tmp[i];
	} else {
		for(int i=1; i<=4; i++) tmp[f(i+n)]=v[i][rc];
		for(int i=1; i<=4; i++) v[i][rc]=tmp[i];
	}
}

deque<int> q;
void dfs(int cnt,int w) {
	if(w > (mn-cnt-1)*4) return;
	if(cntWrong() == 0) {
		if(mn>cnt) {
			mn=cnt;
			for(int i=0; i<cnt; i++) {
				for(int j=0; j<3; j++) {
					ans[i][j]=q[i*3+j];
				}
			}
		}
		return;
	} else if(cnt==7) return;

	for(int i=1; i<=2; i++) {
		for(int j=1; j<=4; j++) {
			for(int k=1; k<=3; k++) {
				q.push_back(i); q.push_back(j); q.push_back(k);
				go(i,j,k);
				dfs(cnt+1,cntWrong());
				go(i,j,4-k);
				q.pop_back(); q.pop_back(); q.pop_back();
			}
		}
	}
}

int main() {
	int wrong = 0;
	for(int i=1; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			ori[i][j] = (i-1)*4+j;
			scanf("%d",&v[i][j]);
			if(v[i][j]!=ori[i][j]) wrong++;
		}
	}
	if(wrong==0) return 0&puts("0");

	dfs(0,wrong);
	printf("%d\n",mn);
	for(int i=0; i<mn; i++) {
		for(int j=0; j<3; j++) {
			printf("%d ",ans[i][j]);
		} puts("");
	}
	return 0;
}
