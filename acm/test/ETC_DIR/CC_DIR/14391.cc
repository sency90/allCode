#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <cassert>
using namespace std;
typedef bitset<20> b20;
typedef pair<int,int> pii;
#define G 0
#define S 1
#define ul() to_ulong()
int n,m;
int v[6][6];
int d[6][6][70000];
int mk(int x, int y, int xe, int ye) {
    int ret=0;
    if(x==xe) {
        for(int i=y; i<=ye; i++) {
            ret*=10;
            ret+=v[x][i];
        }
    } else {
        for(int i=x; i<=xe; i++) {
            ret*=10;
            ret+=v[i][y];
        }
    }
    return ret;
}
inline int to_seq(int x, int y) {
    return (x-1)*m+y;
}
inline pii to_mat(int seq) {
    return pii((seq-1)/m+1, (seq-1)%m+1);
}
int f(int x, int y, b20 b) {
    if(x>n) return 0;
    if(y>m) return f(x+1,1,b);
    if(x==n&&y==m) return mk(x,y,x,y);
    int &ret = d[x][y][b.ul()];
    if(ret!=-1) return ret;
    else ret=0;
    b20 orib = b;
    if(y!=m) {
        int sx=x, sy=y;
        for(int i=y; i<=m; i++) {
            int pos = to_seq(x,i);
            if(!b[pos]) {
                b.set(pos);
                ret = max(ret, f(x,i+1,b)+mk(sx,sy,x,i));
            } else {
                sx=x; sy=i+1;
                //f(x,i+1,b);
            }
        }
    }
    b=orib;
    if(x!=n) {
        int sx=x, sy=y;
        for(int i=x; i<=n; i++) {
            int pos = to_seq(i,y);
            if(!b[pos]) {
                b.set(pos);
                ret = max(ret, f(x,y+1,b)+mk(sx,sy,i,y));
            } else {
                sx=i+1; sy=y;
                //f(x,y+1,b);
            }
        }
    }
    return ret;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%1d",&v[i][j]);
        }
    }
    memset(d,-1,sizeof(d));
    printf("%d\n",f(1,1,b20(0)));
    return 0;
}

