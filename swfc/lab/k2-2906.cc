#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<pii> b[21];
int v[20][20],d[1<<20];
int count(int bit) {
    int ret=0;
    for(;bit;bit>>=1) if(bit&1) ret++;
    return ret;
}
const int inf = 0x3f3f3f3f;
int main() {
    //freopen("input.txt","r",stdin);
    int n,m; scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        b[x].push_back(pii(y,w));
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&v[j][i]);
        }
    }
    for(int i=1; i<=n; i++) {
        sort(b[i].begin(),b[i].end());
        for(int j=1; j<b[i].size(); j++) {
            b[i][j].second+=b[i][j-1].second;
        }
    }
    int lim = 1<<n;
    for(int bit=1; bit<lim; bit++) {
        int cnt = count(bit);
        for(int i=0; i<n; i++) {
            if((bit>>i)&1) {
                int pbit=bit^(1<<i);
                d[bit] = max(d[bit],d[pbit]+v[cnt-1][i]);
            }
        }
        pii tmp(d[bit],inf);
        int sum=0;
        auto it = lower_bound(b[cnt].begin(),b[cnt].end(),tmp);
        if(it!=b[cnt].begin()) {
            it--;
            sum = it->second;
        }
        d[bit]+=sum;
    }
    printf("%d\n",d[lim-1]);
    return 0;
}
