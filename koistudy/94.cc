#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n; scanf("%d", &n);
    int ans = 0x3f3f3f3f;
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        ans = min(ans, x);
    }
    printf("%d", ans);
    return 0;
}
