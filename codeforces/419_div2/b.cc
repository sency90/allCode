#include <iostream>
using namespace std;
typedef long long ll;
ll s[200010], ans[200010];
int main() {
    int n,k,q; scanf("%d%d%d",&n,&k,&q);
    for(int i=0; i<n; i++) {
        int x,y;
        scanf("%d%d", &x,&y);
        s[x]++;
        s[y+1]--;
    }
    for(int i=1; i<=200000; i++) {
        s[i]+=s[i-1];
        if(s[i]>=k) ans[i]=ans[i-1]+1LL;
        else ans[i]=ans[i-1];
    }
    for(int i=0; i<q; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",ans[y]-ans[x-1]);
    }

    return 0;
}
