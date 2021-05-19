#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
vector<int> v[1001];
pii b[1001];
int a[1001];
bool chk[1001], achk[1001], vchk[1001][2];
bool bipartite(int x,int s) {
	if(chk[x]) return false;
	chk[x]=true;
	int lim = v[x].size();
	while(lim--) {
		if(s==v[x].size()) s=0;
		int y = v[x][s];
		if(!b[y].first || bipartite(b[y].first,b[y].second)) {
			b[y].first = x;
			b[y].second = s+1;
			a[x]=y;
			return true;
		}
		s++;
	}
	return false;
}
queue<pii> q;
vector<int> ansA,ansB;
int main() {
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		int k; scanf("%d",&k);
		while(k--) {
			int x; scanf("%d",&x);
			v[i].push_back(x);
		}
	}
	for(int i=1; i<=n; i++) {
		memset(chk,false,sizeof(chk));
		if(bipartite(i,0)) achk[i]=true;
	}

	for(int i=1; i<=n; i++) {
		if(!achk[i]) q.push(pii(i,0)),vchk[i][0]=true;
	}

	while(!q.empty()) {
		pii t = q.front(); q.pop();
		if(t.second) {
			int x=b[t.first].first;
			if(vchk[x][0]) continue;
			vchk[x][0]=true;
			q.push(pii(x,0));
		} else {
			for(int y: v[t.first]) {
				if(vchk[y][1]) continue;
				vchk[y][1]=true;
				q.push(pii(y,1));
			}
		}
	}

	for(int i=1; i<=n; i++) {
		if(!vchk[i][0] && a[i]) ansA.push_back(i);
		if(vchk[i][1] && b[i].first) ansB.push_back(i);
	}

	printf("%lu\n",ansA.size()+ansB.size());
	printf("%lu ",ansA.size()); for(int p: ansA) printf("%d ",p); puts("");
	printf("%lu ",ansB.size()); for(int p: ansB) printf("%d ",p);
	return 0;
}
