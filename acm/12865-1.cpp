#include <stdio.h>
#include <algorithm>
using namespace std;
int v[100001], w[100001];
int d[101][100001];
int f(int x, int k) {
    if(x==0||k<=0) return 0;
    if(d[x][k]>0) return d[x][k];
    if(k-w[x] >=0) return d[x][k] = max(f(x-1, k-w[x])+v[x], f(x-1,k));
    else return d[x][k] = f(x-1,k);
}
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++) {
        scanf("%d%d",&w[i],&v[i]);
    }
    printf("%d\n", f(n,k));
    return 0;
}
