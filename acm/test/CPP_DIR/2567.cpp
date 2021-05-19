#include <stdio.h>
#include <cstring>
using namespace std;
bool chk[102][102];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main() {
    memset(chk, false, sizeof(chk));
    int n, x, y, cnt=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        for(int j=x; j<x+10; j++) {
            for(int k=y; k<y+10; k++) {
                chk[j][k] = true;
            }
        }
    }
    for(int i=1; i<=100; i++) {
        for(int j=1; j<=100; j++) {
            if(chk[i][j]) {
                for(int k=0; k<4; k++) {
                    if(!chk[i+dx[k]][j+dy[k]]) cnt++;
                }
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
