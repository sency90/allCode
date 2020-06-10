#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[3][2][3];
int main() {
    int mn = 0x3f3f3f3f, n,i,j,s,x,t;
    scanf("%d",&n);
    memset(d,0x3f,sizeof(d));
    for(i=0; i<3; i++) scanf("%d", &d[i][0][i]);
    for(i=1, t=1; i<n; i++, t^=1) {
        for(j=0; j<3; j++) {
            scanf("%d", &x);
            for(s=0; s<3; s++) {
                if(i==n-1 && j==s) continue;
                else d[s][t][j] = min(d[s][t^1][(j+1)%3], d[s][t^1][(j+2)%3]) + x;
            }
        }
    }
    for(s=0; s<3; s++) {
        mn = min({mn, d[s][(n-1)&1][(s+1)%3], d[s][(n-1)&1][(s+2)%3]});
    }
    printf("%d", mn);
    return 0;
}
