#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
vector<int> v[2010];
int r[2010][2010];
bool chk[2010];
int src, sink;
int findAugmentingPath(int x, int mn) {
    if(chk[x]) return 0;
    chk[x]=true;

    if(x==sink) return mn;
    for(auto &y:v[x]) {
        if(chk[y]) continue;
        if(r[x][y]<=0) continue;
        int f=findAugmentingPath(y, min(mn,r[x][y]));
        r[x][y]-=f; r[y][x]+=f;
        if(f>0) return f;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m,x;
    cin >>n>>m;
    src=0,sink=n+m+2;
    for(int i=1; i<=n; i++) {
        if(!r[src][i]) {
            v[src].push_back(i);
            v[i].push_back(src);
            r[src][i]=1;
        }
        int t; cin>>t;
        for(int j=0; j<t; j++) {
            cin>>x;
            if(!r[i][x+n]) {
                v[i].push_back(x+n);
                v[x+n].push_back(i);
                r[i][x+n]=1;
                if(!r[x+n][sink]) {
                    v[x+n].push_back(sink);
                    v[sink].push_back(x+n);
                    r[x+n][sink]=1;
                }
            }
        }
    }

    int ans=0;
    while(true) {
        memset(chk, false, sizeof(chk));
        int flow=findAugmentingPath(src,inf);
        if(!flow) break;
        ans+=flow;
    }
    cout << ans;
    return 0;
}
