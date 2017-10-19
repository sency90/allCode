#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int cnt[301][301][11];
bool chk[11];
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int x; scanf("%d", &x);
            cnt[i][j][x]++;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=10; k++) {
                cnt[i][j][k]+=cnt[i-1][j][k]+cnt[i][j-1][k]-cnt[i-1][j-1][k];
            }
        }
    }
    int q; scanf("%d", &q);
    for(int i=0; i<q; i++) {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        memset(chk,false,sizeof(chk));
        for(int k=1; k<=10; k++) {
            if(cnt[x1-1][y1-1][k]-cnt[x2][y1-1][k]-cnt[x1-1][y2][k]+cnt[x2][y2][k]>0) chk[k]=true;
        }
        int cnt=0;
        for(int j=1; j<=10; j++) if(chk[j]) cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
