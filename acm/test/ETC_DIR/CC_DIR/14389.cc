#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char str[11][27];
int v[26][11];
int d[26][11][1100];
int n,m;
bool chk4(int x, int y) {
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            if(v[x+i][y+j]) return false;
        }
    }
    return true;
}
int f(int x, int y, int bit) {
    if(x>=n||y>=m) return 0;
    int &ret = d[x][y][bit];
    if(ret!=-1) return ret;
    else ret=0;

    int nx=x, ny=y+1;
    if(ny==m) nx++, ny=0;

    if((bit&1)||v[x][y]) ret = f(nx,ny,bit>>1);
    else {
        ret = f(nx,ny,bit>>1)+1;
        int nx2=nx, ny2=ny+1;
        if(ny2==m) nx2++, ny2=0;
        if(nx==x && nx<n-1 && !(bit&3)) {
            if(chk4(x,y)) ret = max(ret, f(nx2,ny2,(bit>>2)|(1<<(m-1))|(1<<(m-2)))+16);
        }
    }
    return ret;
}
int main() {
    memset(d,-1,sizeof(d));
    scanf("%d%d",&n,&m);
    int cnt=0;
    for(int i=0; i<n; i++) {
        scanf("%s", str[i]);
        for(int j=0; j<m; j++) {
            if(str[i][j]=='.') v[j][i]=0;
            else if(str[i][j]=='1') {
                v[j][i]=1;
                cnt++;
            }
        }
    }
    swap(n,m);
    printf("%d\n", cnt+f(0,0,0));
    return 0;
}
