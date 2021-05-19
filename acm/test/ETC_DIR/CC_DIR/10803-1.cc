#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
int d[10001][101];
pii p[10001][101];
const int inf = 0x3f3f3f3f;
vector<pii> v;
int f(int n, int m) {
    if(n<m) swap(n,m);
    int &ret = d[n][m];
    if(ret) return ret;
    else ret = inf;
    if(n%m==0) return ret = n/m;

    if(n>3*m) {
        ret = f(n-m,m)+1;
        p[n][m]={n-m,m};
    } else {
        pii co;
        for(int i=1; i<=n-1; i++) {
            int tmp = f(i,m)+f(n-i,m);
            if(ret > tmp) {
                ret = tmp;
                co={i,m};
            }
        }
        for(int i=1; i<=m-1; i++) {
            int tmp = f(n,i)+f(n,m-i);
            if(ret > tmp) {
                ret = tmp;
                co={n,i};
            }
        }
        p[n][m]=co;
    }
    return ret;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    if(n<m) swap(n,m);
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            p[i][j]={-1,-1};
        }
    }
    printf("%d\n", f(n,m));

    for(pii i=p[n][m]; i.first!=-1; i=p[i.first][i.second]) {
        printf("%d %d\n", i.first, i.second);
    }
    return 0;
}
