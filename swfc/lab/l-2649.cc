#include <stdio.h>
const int inf = 0x3f3f3f3f;
int v[21], d[21][21][21], m;
int min(int x, int y) {
    return (x<y)?x:y;
}
int abs(int x) {
    return (x<0)?-x:x;
}
int f(int s, int l, int r) {
    if(s==m) return 0;
    int &ret = d[s][l][r];
    if(ret!=-1) return ret;
    ret = inf;
    if(v[s+1]<r) ret = f(s+1,v[s+1],r)+abs(l-v[s+1]);
    if(v[s+1]>l) ret = min(ret, f(s+1,l,v[s+1])+abs(r-v[s+1]));
    return ret;
}
int main() {
    int n,l,r;
    scanf("%d%d%d%d",&n,&l,&r,&m);
    if(l>r) { l^=r; r^=l; l^=r; } //swap
    
    for(int i=0; i<21; i++) {
        for(int j=0; j<21; j++) {
            for(int k=0; k<21; k++) {
                d[i][j][k]=-1;
            }
        }
    }

    for(int i=1; i<=m; i++) scanf("%d", &v[i]);
    printf("%d\n", f(0,l,r));
    return 0;
}
