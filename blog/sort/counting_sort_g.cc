#include <cstdio>
using namespace std;
int cnt[6];
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    for(int i=1; i<=n; i++) {
        while(cnt[i]--) printf("%d ",i);
    }
    return 0;
}
