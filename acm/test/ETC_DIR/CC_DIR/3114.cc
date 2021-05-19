#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int r,c,n;
int psc[1501][1501], psr[1501][1501], d[1501][1501];
const int inf = 0x3f3f3f3f+1;
int f(int i, int j) {
    if(i==0&&j==0) return 0;
    else if(i==0||j==0) return -inf;
    int &ret = d[i][j];
    if(ret!=-inf) return ret;
    return ret = max({  f(i-1,j) + (psc[i-1][c]-psc[i-1][j]),
                        f(i,j-1) + (psr[r][j-1]-psr[i][j-1]),
                        f(i-1,j-1) + (psr[r][j-1]-psr[i-1][j-1]) + (psc[i-1][c]-psc[i-1][j-1])
                        });
}
int main() {
    char fruit;
    memset(d,0xc0,sizeof(d));
    scanf("%d%d", &r,&c);
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            scanf(" %c%d",&fruit,&n);
            if(fruit == 'A') {
                psr[i][j] = psr[i-1][j]+n;
                psc[i][j] = psc[i][j-1];
            } else {
                psr[i][j] = psr[i-1][j];
                psc[i][j] = psc[i][j-1]+n;
            }
        }
    }
    printf("%d\n", f(r,c));
    return 0;
}
