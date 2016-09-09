#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int sero[501], d[501][101];
int ABS(int x) { return x<0?-x:x; }
int main() {
    int n,m,s,e,del,add;
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&s,&e,&del,&add);
    for(int i=1; i<=m; i++) {
        scanf("%d", &sero[i]);
    }
    memset(d, 0x3f, sizeof(d));
    for(int j=1; j<=n; j++) {
        if(j==s) d[0][j]=0;
        else d[0][j]=ABS(s-j)*add;
    }

    for(int prev_garo=1; prev_garo<=n; prev_garo++) {
        for(int i=1; i<=m; i++) {
            for(int dest_sero=1; dest_sero<=n; dest_sero++) {
                if(prev_garo==dest_sero && (sero[i]==prev_garo || sero[i]+1==prev_garo)) {
                    d[i][dest_sero] = min(d[i][dest_sero], d[i-1][prev_garo] + del);
                } else if((prev_garo<=sero[i]&&sero[i]+1<=dest_sero) || (dest_sero<=sero[i]&&sero[i]+1<=prev_garo)) {
                    d[i][dest_sero] = min(d[i][dest_sero], d[i-1][prev_garo] + (ABS(prev_garo-dest_sero)-1)*add);
                } else {
                    d[i][dest_sero] = min(d[i][dest_sero], d[i-1][prev_garo] + ABS(prev_garo-dest_sero)*add);
                }
            }
        }
    }
    printf("%d", d[m][e]);
    return 0;
}
