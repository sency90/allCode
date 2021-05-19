#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
char s[51][51];
int m[51][51];
const int inf = 0x3f3f3f3f;
int main() {
    int n,d; scanf("%d%d", &n,&d);

    memset(m, 0x3f, sizeof(m));
    for(int i=0; i<n; i++) {
        m[i][i]=0;
        scanf("%s", s[i]);
        for(int j=i+1; j<n; j++) {
            if(s[i][j]=='Y') {
                m[i][j] = m[j][i] = 1;
            }
        }
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            if(k==i) continue;
            for(int j=0; j<n; j++) {
                if(j==i || j==k) continue;
                m[i][j] = min(m[i][j], m[i][k]+m[k][j]);
            }
        }
    }

    int mx = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(m[i][j] == inf) return 0&puts("-1");
            else mx = max(mx, m[i][j]);
        }
    }
    printf("%d\n", d*mx);
    return 0;
}
