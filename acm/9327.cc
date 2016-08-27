#include <cstdio>
#include <algorithm>
using namespace std;
int d[200001], s[101], sum[101];
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n,e;
        scanf("%d%d",&n,&e);
        for(int i=1; i<=n; i++) scanf("%d", &s[i]);
        sort(s+1, s+n+1);
        for(int i=1; i<=n; i++) sum[i]=sum[i-1]+s[i];

        d[0]=tc;
        for(int i=1; i<=n; i++) {
            for(int j=sum[i-1]; j>=0; j--) {
                if(d[j] == tc) {
                    printf("** %d %d\n", i, j);
                    d[s[i]+j] = tc;
                }
            }
        }

        int i;
        for(i=(e+1)/2; i<=sum[n]; i++) {
            if(d[i]==tc) break;
        }

        if(i>sum[n]) puts("FULL");
        else printf("%d\n",i);
    }
    return 0;
}
