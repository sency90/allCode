#include <cstdio>
#include <algorithm>
using namespace std;
int d[10001][101];
const int inf = 0x3f3f3f3f;
int f(int n, int m) {
    if(n<m) swap(n,m);
    int &ret = d[n][m];
    if(ret) return ret;
    else ret = inf;
    if(n%m==0) return ret = n/m;

    if(n>3*m) ret = f(n%m+2*m,m)+n/m-2;
    else {
        for(int i=1; i<=n-1; i++) {
            ret = min(ret, f(i,m)+f(n-i,m));
        }
        for(int i=1; i<=m-1; i++) {
            ret = min(ret, f(n,i)+f(n,m-i));
        }
    }
    return ret;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    if(n<m) swap(n,m);
    printf("%d\n", f(n,m));
    return 0;
}
