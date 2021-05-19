#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
int cost[]={0,1,1,1,2,2,2,1,1,1};
int n, d[100][10][10], disk[100], dest[100], tmp[50];
int c(int x) {
    if(tmp[x]!=-1) return tmp[x];
    return tmp[x] = x%10;
}
int f(int x, int i, int j) {
    if(x==n) return 0;
    int &ret = d[x][i][j];
    if(ret!=inf) return ret;
    for(int n=0; n<10; n++) {
        for(int m=0; m<10; m++) {
            int tc = cost[n]+cost[m] + cost[ c(c(disk[x]+i+n+m) - dest[x] + 10) ];
            ret = min(ret, tc+f(x+1, c(j+n+m), m));
        }
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    memset(d, 0x3f, sizeof(d));
    memset(tmp, -1, sizeof(tmp));
    for(int i=0; i<n; i++) scanf("%1d", &disk[i]);
    for(int i=0; i<n; i++) scanf("%1d", &dest[i]);
    printf("%d", f(0,0,0));
    return 0;
}
