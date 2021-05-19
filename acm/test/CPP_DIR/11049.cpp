#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
int d[501][501];
long long inf = LONG_MAX/2-1;
struct Matrix{
    int r, c;
}v[501];
long long f(int s, int e) {
    if(d[s][e] > 0) return d[s][e];
    if(s==e) return 0LL;
    long long mn=inf, tmp;
    for(int i=s; i<e; i++) {
        if(mn > (tmp = f(s,i)+f(i+1,e) + v[s].r*v[i].c*v[e].c)) mn = tmp;
    }
    return d[s][e] = mn;
}
int main() {
    int n, r, c;
    scanf("%d", &n);
    memset(d, 0, sizeof(d));
    for(int i=0; i<n; i++) {
        scanf("%d %d", &r, &c);
        v[i].r = r;
        v[i].c = c;
    }
    printf("%lld", f(0,n-1));
    return 0;
}
