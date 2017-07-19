#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        int n; scanf("%d", &n);
        int mx=0;
        for(int i=0; i<n; i++) {
            int x; scanf("%d", &x);
            mx = max(mx, x);
        }
        printf("Case %d: %d\n", z,mx);
    }
    return 0;
}
