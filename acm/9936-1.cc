#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
using namespace std;
const int ninf = 0xc0c0c0c0;
const int state[]={0x00,0x11,0x22,0x44,0x03,0x06,0x17,0x47,0x33,0x66,0x55};
const int cnt[]={0,1,1,1,1,1,2,2,2,2,2};

int v[1001][3];
int d[1001][1001][8];

int value(int x, int s) {
    if(x<0 && s) return ninf;
    int ret = 0LL;
    for(int i=0; i<3; i++, s>>=1) ret += (s&1) * v[x][i];
    s>>=1;
    if(x-1<0 && s) return ninf;
    for(int i=0; i<3; i++, s>>=1) ret += (s&1) * v[x-1][i];
    return ret;
}

int solve(int n, int k, int last_left) {
    if (n==0) return k==0? 0:ninf;
    if (k==0) return 0;

    int &ret = d[n][k][last_left];
    if (ret != ninf) return ret;

    for (int ns = 0; ns<11; ns++) {
        int r=state[ns]&0x0f, l=(state[ns]>>4)&0x0f;
        if (last_left&r) continue;
        if(k>=cnt[ns]) ret = max(ret, solve(n-1,k-cnt[ns],l) + value(n-1,state[ns]));
    }
    return ret;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    memset(d, 0xc0, sizeof(d));
    printf("%d\n", solve(n,k,0));
    return 0;
}
