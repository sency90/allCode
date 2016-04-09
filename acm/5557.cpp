#include <stdio.h>
#include <cstring>
using namespace std;
int v[21];
long long d[21][101];
long long f(int x, long long n) {
    if(x<0 || x>20) return 0LL;
    if(n==1) {
        if(v[0] == x) return 1LL;
        else return 0LL;
    }
    if(d[x][n]!=-1) return d[x][n];
    return d[x][n] = f(x-v[n-1], n-1) + f(x+v[n-1], n-1);
}
int main() {
    long long n;
    memset(d, -1, sizeof(d));
    scanf("%lld", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    printf("%lld", f(v[n-1], n-1));
    return 0;

}
