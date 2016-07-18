#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<long long> v;
long long d[2001][2001];
long long f(long long x, int i) {
    if(x==n) return x*v[i];
    int j=i+n-x;
    if(d[x][i]>0LL) return d[x][i];
    return d[x][i]=max(x*v[i]+f(x+1,i+1), x*v[j]+f(x+1,i));
}
int main() {
    scanf("%d", &n);
    v.resize(n+2);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &v[i]);
    }
    printf("%lld",f(0,1));
    return 0;
}
