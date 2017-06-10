#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int v[20][20], d[20][(1<<20)+1], p[(1<<20)+1], last, ans[(1<<20)+1];
int n;
const int inf = 0x3f3f3f3f;
int f(int x,int bit) {
    if(x>=n) return 0;
    int &ret = d[x][bit];
    if(ret!=inf) return ret;
    for(int i=0; i<n; i++) {
        if((bit>>i)&1) continue;
        else {
            int tmp = f(x+1,bit|(1<<i))+v[x][i];
            if(ret > tmp) {
                ret=tmp;
                p[bit]=bit|(1<<i);
                if(x==n-1) last=bit|(1<<i);
            }
        }
    }
    return ret;
}
int main() {
    memset(d,0x3f,sizeof(d));
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&v[i][j]);
        }
    }
    for(int i=0; i<20; i++) {
        ans[1<<i]=i+1;
    }
    printf("%d\n",f(0,0));
    int pv=0;
    for(int i=p[0],j=0; j<n; i=p[i],j++) {
        printf("%d ",ans[i-pv]);
        pv=i;
    }
    return 0;
}
