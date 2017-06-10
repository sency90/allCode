#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
pii d[51][51];
bool chk[51][51];

int s[51][51], v[51];
const int inf = 0x3f3f3f3f;
int dif=inf,n,m;;
inline int ABS(int x){ return (x<0)?-x:x; }
pii f(int x,int y,int idx) {
    if(x==0&&y==0) return pii(inf,0);
    else if(x==0||y==0) return pii(-1,-1);
    //else if(y==0) return pii(0,0);
    pii &ret = d[x][y];
    if(chk[x][y]) return ret;
    chk[x][y]=true;

    int mn=0,mx=inf;
    for(int i=1; y-i>=0; i++) {
        pii tmp = f(x-1,y-i,idx);
        if(tmp.first<0) continue;
        mn = min(tmp.first,s[idx][y]-s[idx][y-i]);
        mx = max(tmp.second,s[idx][y]-s[idx][y-i]);
        if(mx-mn < ret.second-ret.first) ret=pii(mn,mx);
        if(y==m) dif = min(dif,ABS(ret.first-ret.second));
    }
    return ret;
}
void init() {
    memset(chk,false,sizeof(chk));
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            d[i][j]=pii(0,inf);
        }
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++) {
        scanf("%d",&v[i]);
        s[0][i]=s[0][i-1]+v[i];
    }
    for(int j=2; j<=m; j++) {
        for(int i=j,k=1; k<=m; i++,k++) {
            if(i==m+1) i=1;
            s[j-1][k]=s[j-1][k-1]+v[i];
        }
    }
    for(int i=0; i<m; i++) {
        init();
        pii tmp = f(n,m,i);
    }
    printf("%d\n",dif);
    return 0;
}
