#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int v[5001], d[5001][5001], s[5001], p[5001][5001];
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        memset(d, 0x3f, sizeof(d));
        memset(p, 0, sizeof(p));
        memset(s, 0, sizeof(s));
        int n; scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d", &v[i]);
            s[i]=s[i-1]+v[i];
        }
        for(int i=0; i<=n; i++) d[i][i]=0;
        for(int i=1; i<=n; i++) p[i][i]=i;
        for(int len=1; len<=n; len++) {
            for(int i=1; i+len<=n; i++) {
                int j=i+len;
                for(int k=p[i][j-1]; k<=p[i+1][j]; k++) {
                    if(d[i][j]>d[i][k]+d[k+1][j]) {
                        d[i][j]=d[i][k]+d[k+1][j];
                        p[i][j]=k;
                    }
                }
                d[i][j] += s[j]-s[i-1];
            }
        }
        printf("%d\n", d[1][n]);
    }
    return 0;
}
