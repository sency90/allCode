#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v[5001];
int n,k,x;
int d[5001][101][101];
const int inf = 0x3f3f3f3f;
int treeSearch(int cur) {
    int sub1=0,sub2=0,c1=0,c2=0,cost1=0,cost2=0;
    if(v[cur].size()==2) {
        c2=v[cur][1].first;
        sub2=treeSearch(c2);
        cost2=v[cur][1].second;
    }
    if(v[cur].size()>=1) {
        c1=v[cur][0].first;
        sub1=treeSearch(c1);
        cost1=v[cur][0].second;
    }
    for(int i=min(sub1+sub2+1,k); i>=0; i--) d[cur][i][0]=0;
    //d[cur][min(sub1+sub2+1,k)][0]=0;
    for(int k1=min(sub1,k); k1>=0; k1--) {
        for(int x1=min((sub1-k1)/k,x); x1>=0; x1--) {
            for(int k2=min(sub2,k); k2>=0; k2--) {
                for(int x2=min((sub2-k2)/k,x); x2>=0; x2--) {
                    int ncost[4]={0,cost1,cost2,cost1+cost2};
                    int nk[4]={min(k1+k2+1,k),min(k2+1,k),min(k1+1,k),1};
                    int nx[4]={min(x1+x2,x),min(x1+x2+(k1>=k),x),min(x1+x2+(k2>=k),x),min(x1+x2+(k1>=k)+(k2>=k),x)};
                    for(int i=0; i<4; i++) {
                        d[cur][nk[i]][nx[i]] = min(d[cur][nk[i]][nx[i]], d[c1][k1][x1]+d[c2][k2][x2]+ncost[i]);
                    }
                }
            }
        }
    }
    return sub1+sub2+1;
}
int main() {
    memset(d,0x3f,sizeof(d));
    scanf("%d%d%d",&n,&k,&x);
    for(int i=0; i<=1; i++) {
        for(int j=0; j<=k; j++) d[i][j][0]=0;
    }
    for(int i=2; i<=n; i++) {
        int p,cost;
        scanf("%d%d",&p,&cost);
        v[p].push_back(pii(i,cost));
        for(int j=0; j<=k; j++) d[i][j][0]=0;
    }
    treeSearch(1);
    int ans=d[1][k][x-1];
    for(int i=0; i<=k; i++) {
        ans = min(ans,d[1][i][x]);
    }
    if(ans<inf) printf("%d\n", ans);
    else puts("-1");
    return 0;
}

