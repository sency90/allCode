#include <stdio.h>
#include <algorithm>
using namespace std;
long long v[100001];
const long long MOD = 1000000007;
bool cmp(const long long &lhs, const long long &rhs) {
    return lhs > rhs;
}
long long mm(long long x, long long y) {
    return x*y%MOD;
}
long long ms(long long x, long long y) {
    if(x+y >= MOD) return x+y-MOD;
    else return x+y;
}
long long d[100001][51];
long long combi(int n, int c) {
    if(n==c || c==0) return 1LL;
    if(d[n][c]>0LL) return d[n][c];
    else return d[n][c]=ms(combi(n-1,c-1),combi(n-1,c));
}
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) {
        scanf("%lld", &v[i]);
    }
    sort(v, v+n, cmp);
    long long sum=0LL;
    n--; k--;
    for(int i=0; n-i>=k; i++) {
        sum = ms(sum,mm(v[i],combi(n-i,k)));
    }
    printf("%lld", sum);
    return 0;
}
