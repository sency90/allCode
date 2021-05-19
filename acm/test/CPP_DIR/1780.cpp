#include <stdio.h>
int ar[2187][2187];
int cnt[3]={0,0,0};
void solve(int x, int y, int n) {
    bool isBrk = false;
    int cur = ar[x][y];

    for(int i=x+n-1; i>=x; i--) {
        for(int j=y+n-1; j>=y; j--) {
            if(cur != ar[i][j]) {
                isBrk = true;
                break;
            }
        }
        if(isBrk) break;
    }
    if(isBrk) {
        int m = n/3;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                solve(x+i*m, y+j*m, m);
            }
        }
    } else {
        cnt[cur+1]++;
    }
}

int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &ar[i][j]);
        }
    }
    solve(0, 0, n);
    for(int i=0; i<3; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}
