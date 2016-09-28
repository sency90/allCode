#include <cstdio>
using namespace std;
const int mod = 1e9;
int d[201][201];
int f(int n, int k) {
    if(k==1) return 1;
    if(d[n][k]) return d[n][k];
    for(int i=0; i<=n; i++) {
        d[n][k] += f(i,k-1);
        d[n][k] %= mod;
    }
    return d[n][k];
}
int main() {
    int n, k;
    scanf("%d%d",&n,&k);
    printf("%d\n",f(n,k));
    return 0;
}
