#include <stdio.h>
#include <cstring>
using namespace std;
unsigned int v[401][401];
unsigned int inf = 0x77777777;
int main() {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    memset(v, 0x77, sizeof(v));
    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        v[a][b] = c;
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i==j || i==k || j==k) continue;
                if(v[i][j] > v[i][k]+v[k][j]) {
                    v[i][j] = v[i][k]+v[k][j];
                }
            }
        }
    }
    unsigned int mn=inf;
    for(int i=1; i<=n-1; i++) {
        for(int j=i+1; j<=n; j++) {
            if(mn > v[i][j]+v[j][i]) {
                mn = v[i][j]+v[j][i];
            }
        }
    }
    if(mn>=inf) puts("-1");
    else printf("%u", mn);
}
