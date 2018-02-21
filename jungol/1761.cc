#include <stdio.h>
int q[101][3],s[101],b[101];
struct Info{
	int val[3];
	Info(){}
	Info(int x,int y,int z){
		val[0]=x; val[1]=y; val[2]=z;
	}
	void print() {
		for(int i=0; i<3; i++) printf("%d ",val[i]);
		puts("");
	}
}info[721],tmp;
int v[3],cnt;
void dfs(int x,int bit) {
	if(x==3) {
		for(int i=0; i<3; i++) info[cnt].val[i]=v[i];
		cnt++;
		return;
	}

	for(int i=1; i<10; i++) {
		if((bit>>i)&1) continue;
		v[x]=i;
		dfs(x+1,bit|(1<<i));
	}
}
bool noAns[721];
int main() {
	int n; scanf("%d",&n);
	for(int i=0; i<n; i++) {
		int x;
		scanf("%d%d%d",&x,&s[i],&b[i]);
		for(int j=2; j>=0; j--) {
			q[i][j]=x%10;
			x/=10;
		}
	}
	dfs(0,0);

	for(int i=0; i<n; i++) {
		for(int j=0; j<cnt; j++) {
			if(noAns[j]) continue;
			int strike=0, ball=0;
			for(int k=0; k<3; k++) {
				if(q[i][k] == info[j].val[k]) strike++;
				for(int u=0; u<3; u++) {
					if(u==k) continue;
					if(q[i][u] == info[j].val[k]) ball++;
				}
			}
			if(strike!=s[i]) noAns[j]=true;
			if(ball!=b[i]) noAns[j]=true;
		}
	}

	int ans=0;
	for(int i=0; i<cnt; i++) {
		if(!noAns[i]) {
			//info[i].print();
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
