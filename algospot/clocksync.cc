#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int ansclk[16] = {12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12};
int clk[16];
vector<int> sw[10];
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
	int c = cnt*3;
	for(int i=0; i<sw[sno].size(); i++) {
		clk[sw[sno][i]]-=c;
		if(clk[sw[sno][i]]<=0) clk[sw[sno][i]]+=12;
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
	sw[0] = {0,1,2};
	sw[1] = {3,7,9,11};
	sw[2] = {4,10,14,15};
	sw[3] = {0,4,5,6,7};
	sw[4] = {6,7,8,10,12};
	sw[5] = {0,2,14,15};
	sw[6] = {3,14,15};
	sw[7] = {4,5,7,14,15};
	sw[8] = {1,2,3,4,5};
	sw[9] = {3,4,5,9,13};

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
