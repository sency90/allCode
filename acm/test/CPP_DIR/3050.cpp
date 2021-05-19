#include <stdio.h>
char mp[401][402];
int d[401][402];
int main() {
    int r, c, cnt;
    scanf("%d%d ",&r,&c);
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            scanf("%c", &mp[i][j]);
        }
        getchar();
    }
    for(int i=1; i<=r; i++) {
        cnt=0;
        for(int j=1; j<=c; j++) {
            if(mp[i][j]=='X') cnt++;
            d[i][j]=cnt;
        }
    }
    int mx=0, col_len, row_len;
    for(int j=1; j<=c; j++) {
        for(int k=j; k<=c; k++) {
            cnt=0;
            for(int i=1; i<=r; i++) {
                if(d[i][k]-d[i][j-1]==0) {
                    col_len = (k-j+1)*2;
                    row_len = ++cnt*2;
                    if(mx < col_len + row_len) mx = col_len+row_len;
                } else cnt = 0;
            }
        }
    }
    printf("%d", mx-1);
    return 0;
}
