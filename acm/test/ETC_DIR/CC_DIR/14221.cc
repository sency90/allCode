#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v[5001];
priority_queue<pii,vector<pii>,greater<pii>> mnh;
bool chk[5001], home[5001];
int d[5001];
int main() {
    int n,m; scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        v[x].push_back({w,y});
        v[y].push_back({w,x});
    }
    int p,q; scanf("%d%d",&p,&q);
    for(int i=0; i<p; i++) {
        int x; scanf("%d", &x);
        home[x]=true;
    }
    memset(d,0x3f,sizeof(d));
    for(int i=0; i<q; i++) {
        int x; scanf("%d", &x);
        d[x]=0;
        mnh.push({0,x});
    }

    pii t;
    for(int i=0; i<n; i++) {
        while(!mnh.empty()) {
            t=mnh.top(); mnh.pop();
            if(!chk[t.second]) break;
        }
        int dist=t.first, x=t.second;
        chk[x]=true;
        for(pii &c: v[x]) {
            int w=c.first, y=c.second;
            if(chk[y]) continue;
            if(d[y]>dist+w) {
                d[y]=dist+w;
                mnh.push({d[y],y});
            }
        }
    }

    int mn=0x3f3f3f3f, ans=0;
    for(int i=1; i<=n; i++) {
        if(home[i] && mn>d[i]) {
            mn=d[i];
            ans=i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
