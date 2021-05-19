#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii, vector<pii>, greater<pii>> mnh;
vector<pii> v[10010];
int d[10010];
bool chk[10010];
int sum=0;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        v[x].push_back({w,y});
        v[y].push_back({w,x});
        v[x].push_back({0,y+n});
        v[y].push_back({0,x+n});
        v[x+n].push_back({w,y+n});
        v[y+n].push_back({w,x+n});
        sum+=w;
    }
    int s,e;
    scanf("%d%d",&s,&e);
    memset(d,0x3f,sizeof(d));

    pii tmp;
    mnh.push({0,s});
    int lim = n*2;
    for(int i=0; i<lim; i++) {
        while(!mnh.empty()) {
            tmp=mnh.top(); mnh.pop();
            if(!chk[tmp.second]) break;
        }
        int x=tmp.second, dist=tmp.first;
        chk[x]=true;
        for(pii &u: v[x]) {
            int y=u.second, w=u.first;
            if(chk[y]) continue;
            if(d[y] > dist+w) {
                d[y]=dist+w;
                mnh.push({d[y],y});
            }
        }
    }
    int mn = min(d[e],d[e+n]);
    printf("%d\n", sum-mn);
    return 0;
}
