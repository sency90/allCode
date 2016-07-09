#include <stdio.h>
int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={-1,-1,0,1,1,1,0,-1};
bool chk[4][3];
int main() {
    int n, d;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%1d", &d);
        if(d==0) d=10;
        else d--;

        chk[d/3][d%3] = true;
    }
    int nx, ny, cnt=0;
    for(int z=0; z<=10; z++) {
        if(z==9) continue;
        bool good = true, hasGood = false;
        for(int i=0; i<8; i++) {
            nx = z+dx[i]; ny = z+dy[i];
            if(nx<0||nx>=3||ny<0||ny>=3) {
                if(nx==2&&ny==1) {
                } else {
                    good = false;
                    break;
                }
            }
        }
        if(good) cnt++;
    }
    if(cnt==9)
}
