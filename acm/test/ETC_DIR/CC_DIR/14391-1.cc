#include <cstdio>
#include <bitset>
#include <cstring>
#include <cassert>
using namespace std;
#define ul() to_ulong()
typedef pair<int,int> pii;
typedef bitset<20> b20;
const int inf = 0x3f3f3f3f;
int v[6][6];
int n,m;
int mk(int x, int y, int xe, int ye) {
    if(!(x<=xe && y<=ye)) return 0;
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
int seq(int x, int y) { return x*m+y; }
pii mat(int s) { return {s/m,s%m}; }

int mask;
int f(int x, int y, int bit) {
    if(bit==mask) return 0;
    else {
        bitset<20> b(bit);
        if(y>=m) {
            for(int i=0; i<n*m; i++) {
                if(!b[i+1]) {
                    pii p=mat(i);
                    return f(p.first,p.second,bit);
                }
            }
        } else if(x>=n) {
            for(int i=0; i<n*m; i++) {
                if(!b[i+1]) {
                    pii p=mat(i);
                    return f(p.first,p.second,bit);
                }
            }
        }
    }
    int ret = 0;
    bitset<20> b(bit);
    int xs=x, ys=y;
    for(int i=y; i<m; i++) {
        int pos = seq(x,i);
        if(!b[pos+1]) {
            b.set(pos+1);
            ret = max(ret, f(x,i+1,b.ul())+mk(xs,ys,x,i));
        } else xs=x, ys=i+1;
    }
    b=bitset<20>(bit);
    for(int i=x; i<n; i++) {
        int pos = seq(i,y);
        if(!b[pos+1]) {
            b.set(pos+1);
            ret = max(ret, f(x,i+1,b.ul())+mk(xs,ys,i,y));
        } else xs=i+1, ys=y;
    }
    return ret;
}
int main() {
    scanf("%d%d",&n,&m);
    mask = (1<<n*m)-1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d",&v[i][j]);
        }
    }
    printf("%d\n",f(0,0,0));
    return 0;
}
