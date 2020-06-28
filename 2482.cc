#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1e9+3;
const int inf = 0x3f3f3f3f;
int d[1001][1001];
int f(int x, int y) {
    if(x<y*2) return 0;
    else if(x==y*2) return 2;
    else if(y==0) return 1;
    else if(y==1) return x;

    int &ret = d[x][y];
    if(ret!=inf) return ret;
    else return ret = (f(x-2,y-1)+f(x-1,y))%MOD;
}
int main() {
    memset(d, 0x3f, sizeof(d));
    int n, k; scanf("%d%d",&n,&k);
    printf("%d", f(n,k));
    return 0;
}
