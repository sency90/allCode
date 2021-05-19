#include <cstdio>
#include <algorithm>
using namespace std;
int d[10001][2], v[10001];
int f(int x, int y) {
    if(x<=0) return 0;
    int &ret = d[x][y];
    if(ret) return ret;
    if(y==1) ret = max(f(x-2,0),f(x-1,0))+v[x];
    else if(y==0) ret = max(f(x-2,1)+v[x-1],f(x-1,1));
    return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d",&v[i]);
    f(n,1); f(n,0);
    printf("%d\n",max({d[n-1][1]+v[n],d[n][1],d[n][0]}));
    return 0;
}
