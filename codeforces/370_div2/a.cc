#include <cstdio>
using namespace std;
long long v[100010];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &v[i]);
    }
    for(int i=1; i<=n; i++) {
        printf("%lld ", v[i]+v[i-1]);
    }
    return 0;
}
