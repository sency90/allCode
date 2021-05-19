#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
int inIdx[1001];
vector<int> pre, in;
void mkPost(int s, int e, int rIdx) {
    if(s==e) return;
    mkPost(s+1, inIdx[pre[s]]-s, rIdx+1);
    mkPost(inIdx[pre[s]]-s+1, e, rIdx+1);
    printf("%d ", pre[rIdx]);
}
int main() {
    int tc, n;
    scanf("%d", &tc);
    while(tc--) {
        pre.clear(), in.clear();
        scanf("%d", &n);
        pre.resize(n); in.resize(n);
        memset(inIdx, 0, sizeof(inIdx));
        for(int i=0; i<n; i++) {
            scanf("%d", &pre[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &in[i]);
            inIdx[in[i]] = i;
        }
        mkPost(0,n,0);
        puts("");
    }
    return 0;
}
