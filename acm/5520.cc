#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int ansclk[9] = {12,12,12,12,12,12,12,12,12};
int clk[9];
vector<int> sw[9];
char swc[9][10];
int ans,mnans;
void push(int sno, int cnt) {
	if(cnt==0) return;
	int c = cnt*3;
	for(int i=0; i<sw[sno].size(); i++) {
		clk[sw[sno][i]]+=c;
		if(clk[sw[sno][i]]>12) clk[sw[sno][i]]-=12;
	}
}
void unpush(int sno, int cnt) {
	if(cnt==0) return;
	for(int i=0; i<sw[sno].size(); i++) {
		clk[sw[sno][i]]-=cnt;
		if(clk[sw[sno][i]]<0) clk[sw[sno][i]]+=4;
	}
}
void dfs(int sno) {
	if(sno==10) {
		if(memcmp(ansclk, clk, sizeof(ansclk)) == 0) {
			mnans = min(mnans, ans);
		}
		return;
	}
	for(int i=0; i<=3; i++) {
		ans+=i;
		push(sno, i);
		dfs(sno+1);
		unpush(sno, i);
		ans-=i;
	}
}
int main() {
	int tc; scanf("%d", &tc);
	strcpy(swc[0],"ABDE");
	strcpy(swc[1],"ABC");
	strcpy(swc[2],"BCEF");
	strcpy(swc[3],"ADG");
	strcpy(swc[4],"BDEFH");
	strcpy(swc[5],"CFI");
	strcpy(swc[6],"DEGH");
	strcpy(swc[7],"GHI");
	strcpy(swc[8],"EFHI");

	for(int i=0; i<9; i++) {
		int len = strlen(swc[i]);
		for(int j=0; j<len; j++) {
			sw[i].push_back(swc[i][j]-'A');
		}
	}

	const int inf = 0x3f3f3f3f;
	while(tc--) {
		ans=0;
		mnans = inf;
		for(int i=0; i<16; i++) {
			scanf("%d", &clk[i]);
		}

		dfs(0);
		if(mnans == inf) puts("-1");
		else printf("%d\n", mnans);
	}
	return 0;
}
