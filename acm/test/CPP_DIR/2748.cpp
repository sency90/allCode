#include <stdio.h>
#include <cstring>
using namespace std;
long long d[91];
long long f(int x) {
    if(d[x]>0) return d[x];
    if(x==0) return 0;
    else if(x==1) return 1;
    return d[x] = f(x-1) + f(x-2);
}
int main() {
    memset(d, 0, sizeof(d));
    int n; scanf("%d", &n);
    printf("%lld", f(n));
    return 0;
}
