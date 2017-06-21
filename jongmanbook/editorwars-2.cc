#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char s[4];
int p[100000], cnt[100000], e[100000];
void init(int n) {
    for(int i=0; i<n; i++) {
        p[i]=i;
        cnt[i]=1;
    }
    memset(e,-1,sizeof(e));
}
int find(int x) {
    if(x==p[x]) return x;
    else return p[x]=find(p[x]);
}
int uni(int x, int y) {
    if(x==-1||y==-1) return max(x,y);
    x=find(x); y=find(y);
    if(x!=y) {
        cnt[x]+=cnt[y];
        p[y]=x;
    }
    return x;
}
int ack(int x, int y) {
    x=find(x); y=find(y);
    if(x==e[y] || y==e[x]) return false;
    int u=uni(x,y), v=uni(e[x],e[y]);
    if(v!=-1) e[u]=v,e[v]=u;
    return true;
}
int dis(int x, int y) {
    x=find(x); y=find(y);
    if(x==y || (e[x]==e[y] && e[x]!=-1)) return false;
    int u=uni(x,e[y]), v=uni(e[x],y);
    e[u]=v; e[v]=u;
    return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n,m,err=0;
        scanf("%d%d", &n,&m);
        init(n);
        for(int i=1; i<=m; i++) {
            int x,y;
            scanf("%s%d%d",s,&x,&y);
            if(err) continue;
            if(s[0]=='A') {
                if(!ack(x,y)) err=i;
            } else if(!dis(x,y)) err=i;
        }
        if(err) printf("CONTRADICTION AT %d\n", err);
        else {
            int ans=0;
            for(int i=0; i<n; i++) {
                if(i==p[i]) {
                    if(e[i]>i) continue;
                    if(e[i]==-1) ans += cnt[i];
                    else ans += max(cnt[i], cnt[e[i]]);
                }
            }
            printf("MAX PARTY SIZE IS %d\n", ans);
        }
    }
    return 0;
}
