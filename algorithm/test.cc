#include <cstdio>
#include <algorithm>
using namespace std;
int v[10001];
bool cmp(const int &x, const int &y) {
    return x<y;
}
int main() {
    int n;
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    sort(v, v+n, cmp);
    for(int i=0; i<n; i++) printf("%d ", v[i]);
    return 0;
}
