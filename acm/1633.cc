#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define BLACK 0
#define WHITE 1
const int inf = 0x3f3f3f3f+1;
int v[1001][2], d[1001][16][16];
int f(int i, int b, int w) {
    if(i==0 && b==0 && w==0) return 0;
    else if(i<b+w || b<0 || w<0) return -inf;
    int &ret = d[i][b][w];
    if(ret!=-inf) return ret;
    return ret = max({f(i-1,b,w), f(i-1,b-1,w)+v[i][0], f(i-1,b,w-1)+v[i][1]});
}
int main() {
    int i=1;
    memset(d, 0xc0, sizeof(d));
    for(; ~scanf("%d",&v[i][0]); i++) scanf("%d", &v[i][1]);
    printf("%d", f(--i,15,15));
    return 0;
}
