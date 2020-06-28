#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[1000001], p[1000001];
const int inf = 0x3f3f3f3f;
int f(int x) {
    if(x==1) return 0;
    int &ret = d[x];
    if(ret!=inf) return ret;
    else {
        ret=f(x-1)+1;
        p[x] = x-1;
    }

    int pret = ret;
    if(x%2==0) {
        ret = min(ret,f(x/2)+1);
        if(pret!=ret) p[x] = x/2;
    }
    pret = ret;
    if(x%3==0) {
        ret = min(ret,f(x/3)+1);
        if(pret!=ret) p[x] = x/3;
    }
    return ret;
}
int main() {
    memset(d, 0x3f, sizeof(d));
    int n; scanf("%d",&n);
    printf("%d\n", f(n));

    while(n!=1) {
        printf("%d ", n);
        n = p[n];
    }
    puts("1");
    return 0;
}
