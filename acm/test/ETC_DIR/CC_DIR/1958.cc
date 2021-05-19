#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
char x[101], y[101], z[101];
int d[101][101][101];
int f(int i, int j, int k) {
    if(i<0 || j<0 || k<0) return 0;
    if(d[i][j][k]!=-1) return d[i][j][k];
    if(x[i]==y[j] && y[j]==z[k]) return d[i][j][k] = f(i-1,j-1,k-1)+1;
    else return d[i][j][k] = max({f(i,j,k-1), f(i,j-1,k), f(i-1,j,k)});
}
int main() {
    memset(d, -1, sizeof(d));
    scanf("%s%s%s",x,y,z);
    printf("%d", f(strlen(x)-1,strlen(y)-1,strlen(z)-1));
    return 0;
}
