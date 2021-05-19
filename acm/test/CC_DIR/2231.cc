#include <cstdio>
using namespace std;
int ans[1000001];
int f(int x) {
    int ret=x;
    while(x!=0) {
        ret+=x%10;
        x/=10;
    }
    if(ret>1000000) return 0;
    else return ret;
}
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        int x = f(i);
        if(ans[x]==0) ans[x] = i;
    }
    printf("%d\n", ans[n]);
    return 0;
}
