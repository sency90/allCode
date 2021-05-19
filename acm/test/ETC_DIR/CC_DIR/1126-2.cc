#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int d[50][500001], v[50];
const int ninf = 0xc0c0c0c0;
int f(int x, int dif) {
    if(x==-1) {
        if(dif==0) return 0;
        else return ninf;
    }
    int &ret = d[x][dif];
    if(ret!=ninf) return ret;
    ret = max(ret,f(x-1,dif));
    ret = max(ret,f(x-1,abs(dif-v[x]))+v[x]);
    return ret = max(ret,f(x-1,abs(dif+v[x]))+v[x]);
}
int main() {
    int n;
    scanf("%d", &n);
    memset(d,0xc0,sizeof(d));
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    int ans = f(n-1,0);
    if(ans<=0) puts("-1");
    else printf("%d\n", ans/2);
    return 0;
}
