#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int v[101];
int main() {
    int n,mx=1; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        v[x]++;
        mx = max(mx, v[x]);
    }
    printf("%d", mx);
    return 0;
}
