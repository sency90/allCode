#include <stdio.h>
int a[101][101];
int main() {
    int h,w; scanf("%d%d",&h,&w);
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int l,d,x,y;
        scanf("%d%d%d%d",&l,&d,&x,&y);
        if(d==0) {
            for(int v=0; v<l; v++) {
                a[x][y+v]=1;
            }
        } else {
            for(int u=0; u<l; u++) {
                a[x+u][y]=1;
            }
        }
    }
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            printf("%d ", a[i][j]);
        } puts("");
    }
    return 0;
}
