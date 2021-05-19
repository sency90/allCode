#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
int d[10001][101];
int f(int n, int m) {
    if(n<m) swap(n,m);
    if(m==0) return 0;
    int &ret = d[n][m];
    if(ret) return ret;
    else ret = inf;

    if(n>3*m) ret = n/m-1+f(m,n%m+m);
    else {
        for(int i=1; i<=m-1; i++) {
            ret = min(ret, n/i+f(i, n%i) + n/(m-i)+f(m-i, n%(m-i)));
        }
    }
    return ret;
}
int main() {
    int n,m;
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    while(~scanf("%d%d",&n,&m)) {
        printf("%d %d %d\n", n,m,f(n,m));
    }
    return 0;
}
