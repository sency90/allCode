#include <stdio.h>
#include <cstring>
using namespace std;
char a[2501];
int d[2501][2501];
int isP(int x, int y) {
    if(d[x][y] > 0) return d[x][y];
    if(y-x==0) d[x][y]=2;
    else if(y-x==1) {
        if(a[x]==a[y]) d[x][y]=2;
        else d[x][y]=1;
    } else {
        if(a[x]==a[y]) {
            if(isP(x+1, y-1)==2) d[x][y]=2;
            else d[x][y]=1;
        }
    }
    return d[x][y];
}
int dp[2501], len;
int f(int e) {
    if(dp[e]>0) return dp[e];
    if(e==0) return dp[e]=1;
    int tmp, mn=2500;
    for(int i=e; i>=1; i--) {
        if(isP(i,e)==2) {
            tmp = f(i-1);
            if(tmp < mn) mn=tmp;
        }
    }
    if(isP(0,e)==2) mn=0;
    return dp[e] = mn+1;
}
int main() {
    memset(d, 0, sizeof(d));
    memset(dp, 0, sizeof(dp));
    scanf("%s", a);
    len = strlen(a);
    f(len-1);
    printf("%d", f(len-1));
    return 0;
}
