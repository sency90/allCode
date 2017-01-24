#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
int d[10001][101];
int f(int n, int m) {
    if(n<m) swap(n,m);
    if(m==0) return 0;
    if(n%m==0) return n/m;
    int &ret = d[n][m];
    if(ret) return ret;
    else ret = inf;

    for(int i=1; i<=m-1; i++) {
        ret = min(ret, n/i+f(i,n%i)+n/(m-i)+f(m-i, n%(m-i)));
    }
    return ret;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d", f(n,m));
    return 0;
}
