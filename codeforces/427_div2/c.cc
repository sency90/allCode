#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int v[101][101][11];
int main() {
    int n,q,c;
    scanf("%d%d%d",&n,&q,&c);
    for(int i=0; i<n; i++) {
        int x,y,s;
        scanf("%d%d%d",&x,&y,&s);
        v[x][y][s]++;
    }
    for(int i=1; i<=100; i++) {
        for(int j=1; j<=100; j++) {
            for(int k=0; k<=c; k++) {
                v[i][j][k] = v[i][j][k]+v[i][j-1][k]+v[i-1][j][k]-v[i-1][j-1][k];
            }
        }
    }
    for(int i=0; i<q; i++) {
        ll ans=0LL;
        int t,x1,y1,x2,y2,cnt=0;
        scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
        int idx = t%(c+1);
        for(int k=0; k<=c; k++) {
            cnt = v[x2][y2][k]-v[x1-1][y2][k]-v[x2][y1-1][k]+v[x1-1][y1-1][k];
            ans+=((idx+k)%(c+1))*cnt;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
