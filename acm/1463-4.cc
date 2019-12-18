#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int d[1000001];
const int inf = 0x3f3f3f3f;
int f(int x) {
    if(d[x]!=inf) return d[x];
    if(x==1) return 0;

    if(x%3==0) d[x]=min(d[x],f(x/3)+1);
    if(x%2==0) d[x]=min(d[x],f(x/2)+1);
    d[x]=min(d[x],f(x-1)+1);

    return d[x];
}
int main() {
    memset(d, 0x3f, sizeof(d));
    int x; scanf("%d", &x);
    printf("%d", f(x));
    return 0;
}
