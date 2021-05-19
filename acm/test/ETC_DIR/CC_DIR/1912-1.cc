#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int ninf = 0xc0c0c0c0;
int v[100001], d[100001];
int f(int x) {
    if(x==0) return 0;
    if(d[x]!=ninf) return d[x];
    return d[x] = max(f(x-1)+v[x], v[x]);
}
int main() {
    int n;
    scanf("%d", &n);
    memset(d, 0xc0, sizeof(d));
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    f(n);
    int mx = ninf;
    for(int i=1; i<=n; i++) {
        mx = max(mx, d[i]);
    }
    printf("%d", mx);
    return 0;
}
