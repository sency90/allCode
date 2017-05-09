#include <cstdio>
using namespace std;
long long v[101];
int main() {
    v[1]=v[2]=1LL;
    int n; scanf("%d", &n);
    for(int i=1; i<=n-2; i++) {
        v[i+2]=v[i+1]+v[i];
    }
    printf("%lld", v[n]);
    return 0;
}
