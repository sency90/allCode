#include <cstdio>
using namespace std;
int mod = 10007;
int d[1001];
int f(int x) {
    if(x<=1) return 1;
    if(d[x]) return d[x];
    return d[x]=(f(x-1)+f(x-2))%mod;
}
int main() {
    int n; scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}
