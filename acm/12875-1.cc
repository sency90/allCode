#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
char tmp[51][51];
vector<int> v[51];
int chk[51];
int gmx, mxi;
queue<int> q;
void dfs(int x, int mx) {
    chk[x]=1;
    for(int y: v[x]) {
        if(chk[y]) continue;
        dfs(y, mx+1);
    }
    if(gmx < mx) {
        gmx=mx;
        mxi=x;
    }
}
void dfs2(int x, int level) {
    //printf("x: %d, level: %d\n", x,level);
    chk[x]=level;
    for(int y: v[x]) {
        if(chk[y] > level+1) {
            dfs2(y, level+1);
        }
    }
}
int main() {
    int n,d; scanf("%d%d", &n,&d);
    for(int i=0; i<n; i++) {
        scanf("%s", tmp[i]);
        for(int j=0; j<n; j++) {
            if(tmp[i][j]=='Y') {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    gmx=-1;
    dfs(1,0);
    for(int i=0; i<n; i++) {
        if(!chk[i]) return 0&puts("-1");
    }

    memset(chk,0x3f,sizeof(chk));
    dfs2(mxi,0);

    gmx=0;
    for(int i=0; i<n; i++) {
        if(gmx < chk[i]) gmx=chk[i];
    }
    printf("%d\n", gmx*d);
    return 0;
}
