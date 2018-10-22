#include <cstdio>
#include <cstring>
using namespace std;
int d[1001];
int f(int x) {
    if(x<=1) return 1;
    if(d[x]>=0) return d[x];
    else d[x]=0;

    return d[x] = (f(x-1)+f(x-2)) % 10007;
}
int main() {
    memset(d,-1,sizeof(d));
    int n; scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}
