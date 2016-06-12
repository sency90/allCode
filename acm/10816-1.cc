#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n, m, d;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &d);
        auto it = equal_range(v.begin(), v.end(), d);
        printf("%d ", it.second - it.first);
    }
    return 0;
}
