#include <stdio.h>
#include <cstring>
using namespace std;
int pre[1001], in[1001];
void f(int s, int e, int r) {
    for(int i=s; i<e; i++) {
        if(pre[r] == in[i]) {
            f(s,i,r+1);
            f(i+1,e,r+i-s+1);
            printf("%d ", pre[r]);
            return;
        }
    }
}
int main() {
    int tc, n;
    scanf("%d", &tc);
    while(tc--) {
        memset(pre, 0, sizeof(pre));
        memset(in, 0, sizeof(in));
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &pre[i]);
        for(int i=0; i<n; i++) scanf("%d", &in[i]);
        f(0,n,0);
        puts("");
    }
    return 0;
}
