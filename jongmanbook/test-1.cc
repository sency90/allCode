#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char s[4];
int p[100001], cnt[100001], enemy[100001];
bool chk[100001];
void init(int n) {
    for(int i=0; i<n; i++) p[i]=i;
    for(int i=0; i<n; i++) cnt[i]=1;
    memset(enemy,-1,sizeof(enemy));
    memset(chk,false,sizeof(chk));
}
int find(int x) {
    if(x==-1) return -1;
    if(x==p[x]) return x;
    else return p[x]=find(p[x]);
}
int uni(int x, int y) {
    if(x==-1||y==-1) return max(x,y);
    x=find(x); y=find(y);
    if(x!=y) {
        p[y]=x;
        cnt[x]+=cnt[y];
    }
    return x;
}
bool ack(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return true;
    if(enemy[y]==x||enemy[x]==y) return false;
    int px = uni(x,y);
    int z = uni(enemy[x],enemy[y]);
    if(z!=-1) {
        if(z==px) return false;
        enemy[px]=z, enemy[z]=px;
    }
    return true;
}
bool dis(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    //if(enemy[x]==enemy[y] && enemy[x]!=-1) return false;
    uni(enemy[y],x); uni(enemy[x],y);
    //if(x==1 && y==3) puts("gotcha!");
    enemy[x]=find(y); enemy[y]=find(x);
    return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int tc; scanf("%d",&tc);
    while(tc--) {
        int n,m; scanf("%d%d", &n,&m);
        init(n);
        int err=0;
        for(int i=1; i<=m; i++) {
            int x,y;
            scanf("%s%d%d",s,&x,&y);
            if(s[0]=='A' && !err) {
                if(!ack(x,y)) err=i;
            } else {
                if(!dis(x,y)) err=i;
            }
        }
        if(err) printf("CONTRADICTION AT %d\n", err);
        else {
            //for(int i=0; i<n; i++) printf("cnt[%d]: %d\n",i,cnt[i]);
            int sz=0;
            for(int i=0; i<n; i++) {
                if(i==p[i]) {
                    if(enemy[i]==-1) {
                        sz+=cnt[i];
                    }
                    else {
                        if(!chk[enemy[i]]) {
                            sz += max(cnt[i], cnt[enemy[i]]);
                            chk[i]=true;
                            chk[enemy[i]]=true;
                        }
                    }
                }
            }
            printf("MAX PARTY SIZE IS %d\n", sz);
        }
    }
    return 0;
}
