#include <cstdio>
using namespace std;
const int m = (1<<16)-1;
int v[1000001], cnt[m+1], order[1000001], ans[1000001];
void csort(int n) {
    for(int i=0; i<n; i++) cnt[v[i]&m]++;
    for(int i=1; i<=m; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--) order[--cnt[v[i]&m]] = i;

    for(int i=0; i<=m; i++) cnt[i]=0;

    for(int i=0; i<n; i++) cnt[v[i]>>16]++;
    for(int i=1; i<=m; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--) ans[--cnt[v[order[i]]>>16]] = v[order[i]];
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    csort(n);
    for(int i=0; i<n; i++) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}
