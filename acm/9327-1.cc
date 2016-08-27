#include <cstdio>
using namespace std;
int s[101], sum[101], d[200001];
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n,e;
        scanf("%d%d", &n,&e);
        d[0]=tc;
        for(int i=1; i<=n; i++) {
            scanf("%d", &s[i]);
            sum[i] = sum[i-1]+s[i];
        }
        for(int i=1; i<=n; i++) {
            for(int j=sum[i-1]; j>=0; j--) {
                if(d[j]==tc) d[j+s[i]]=tc;
            }
        }

        int i;
        for(i=(e+1)/2; i<=sum[n]; i++) {
            if(d[i]==tc) break;
        }
        if(i>sum[n]) puts("FULL");
        else printf("%d\n", i);
    }
    return 0;
}
