#include <cstdio>
const int MOD = 10007;
using namespace std;
int d[1001][1001];
int f(int n, int k) {
    if(k==0 || k==n) return 1;
    if(d[n][k] > 0) return d[n][k];
    return d[n][k] = (f(n-1,k) + f(n-1,k-1))%MOD;
}
int main() {
    int n, k;
    scanf("%d%d",&n,&k);
    printf("%d", f(n,k));
    return 0;
}
