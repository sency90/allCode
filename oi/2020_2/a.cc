#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int v[5001];
bool cmp(const int & lhs, const int & rhs) {
    return lhs > rhs;
}
int main() {
    int n,k; scanf("%d%d", &n,&k);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v, v+n, cmp);

    for(int i=1; i<n; i++) {
        v[i] += v[i-1];
    }

    printf("%d", v[k-1] - k*(k-1)/2);
    return 0;
}
