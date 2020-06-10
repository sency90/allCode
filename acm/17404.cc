#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
int e, v[1001][3], d[1001][3];
int f(int x, int c) {
    if(x==0) {
        if(c==e) return inf;
        else return v[x][c];
    }
    int &ret = d[x][c];
    if(ret!=inf) return ret;

    return ret = min(f(x-1, (c+2)%3),f(x-1, (c+1)%3)) + v[x][c];
}

int main() {
    int n,i,j; scanf("%d", &n);
    for(i=0; i<n; i++) {
        for(j=0; j<3; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    int mn = inf;
    for(i=0; i<3; i++) {
        e = i;
        memset(d, 0x3f, sizeof(d));
        mn = min(mn, f(n-1,i));
    }
    printf("%d", mn);
    return 0;
}
