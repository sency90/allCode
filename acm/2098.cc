#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, allbit;
int v[16][16];
int d[16][1<<16];
const int inf = 0x3f3f3f3f;
int f(int y, int bit) {
    if(bit == allbit) {
        if(v[y][0]==0) return inf;
        else return v[y][0];
    }
    int &ret = d[y][bit];
    if(ret != inf) return ret;

    for(int i=0; i<n; i++) {
        if(v[y][i]==0) continue;
        if((bit>>i) & 1) continue;
        ret = min(ret, f(i, bit|(1<<i)) + v[y][i]);
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    allbit = (1<<n)-1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    memset(d, 0x3f, sizeof(d));
    printf("%d", f(0,1));
    return 0;
}
