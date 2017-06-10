#include <iostream>
using namespace std;
int v[17][17];
int d[(1<<17)+1];
int n;
int cnt(int bit) {
    int ret=0;
    for(int i=bit; i; i>>=1) if(i&1) ret++;
    return ret;
}
int main() {
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&v[i][j]);
        }
    }
    d[0]=1;
    int lim = 1<<n;
    for(int bit=1; bit<lim; bit++) {
        int tmp = cnt(bit)-1;
        for(int i=0; i<n; i++) {
            if((bit>>i)&1) d[bit] += d[bit^(1<<i)]*v[tmp][i];
        }
        d[bit]=d[bit]%10000;
    }
    printf("%d\n",d[lim-1]);
    return 0;
}
