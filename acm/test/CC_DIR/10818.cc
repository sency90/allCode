#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n; scanf("%d", &n);
    int mn=0x3f3f3f3f, mx=-0x3f3f3f3f;
    int x;
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        mn = min(mn, x);
        mx = max(mx, x);
    }
    printf("%d %d\n", mn, mx);
    return 0;
}
