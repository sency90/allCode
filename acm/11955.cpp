#include <stdio.h>
char win[101][102];
int cnt[101][101];
int main() {
    int n, m, k, sx=1, ex, sy=1, ey;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<n; i++) {
        scanf("%s", win[i]);
    }
    n--; m--;
    ex=sx+k-3;
    ey=sy+k-3;
    for(int i=sx; i<=ex; i++) {
        for(int j=sy; j<=ey; j++) {
            if(win[i][j]=='*') {
                cnt[sx][sy]++;
            }
        }
    }
    sx++; ex++;
    while(ex < n) {
        cnt[sx][sy] = cnt[sx-1][sy];
        for(int i=sy; i<=ey; i++) {
            if(win[sx-1][i]=='*') cnt[sx][sy]--;
            if(win[ex][i]=='*') cnt[sx][sy]++;
        }
        sx++; ex++;
    }
    sy=2; ey=sy+k-3;
    sx=1; ex=sx+k-3;
    while(ex < n) {
        while(ey < m) {
            cnt[sx][sy] = cnt[sx][sy-1];
            for(int i=sx; i<=ex; i++) {
                if(win[i][sy-1]=='*') cnt[sx][sy]--;
                if(win[i][ey]=='*') cnt[sx][sy]++;
            }
            sy++; ey++;
        }
        sx++; ex++;
        sy=2; ey=sy+k-3;
    }
    int mx = 0, x, y;
    for(int i=1; i<=n-(k-2); i++) {
        for(int j=1; j<=m-(k-2); j++) {
            if(mx < cnt[i][j]) {
                mx = cnt[i][j];
                x=i; y=j;
            }
        }
    }
    printf("%d\n", cnt[x][y]);
    sx=x-1; sy=y-1;
    ex=sx+k-1; ey=sy+k-1;
    for(int i=0; i<=n; i++) {
        if(i==sx || i==ex) {
            for(int j=0; j<=m; j++) {
                if(j==sy || j==ey) putchar('+');
                else if(j>sy && j<ey) putchar('-');
                else putchar(win[i][j]);
            }
        } else if(i>sx && i<ex) {
            for(int j=0; j<=m; j++) {
                if(j==sy || j==ey) putchar('|');
                else putchar(win[i][j]);
            }
        } else {
            for(int j=0; j<=m; j++) {
                putchar(win[i][j]);
            }
        }
        puts("");
    }
    return 0;
}
