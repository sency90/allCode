#include <cstdio>
#include <cstring>
using namespace std;
int d[1000001];
int f(int x) {
    if(x==0 || x==1) return 1;
    if(d[x]>=0) return d[x];
    return d[x] = (f(x-1)+f(x-2))%15746;
}
int main() {
    int n; scanf("%d",&n);
    memset(d, -1, sizeof(d));
    printf("%d\n", f(n));
    return 0;
}
