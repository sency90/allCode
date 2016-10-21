#include <cstdio>
using namespace std;
int ans[501];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) {
        scanf("%d",&ans[i]);
    }
    int cnt=0;
    for(int i=1; i<n; i++) {
        if(ans[i]+ans[i-1]<k) {
            int tmp = k-ans[i]-ans[i-1];
            ans[i]+=tmp;
            cnt+=tmp;
        } else continue;
    }
    printf("%d\n", cnt);
    for(int i=0; i<n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
