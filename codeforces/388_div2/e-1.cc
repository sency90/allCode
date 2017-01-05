#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int v[100001],n;
double seg[100001],ans;
void add(int at, int by) { for(int i=at; i<=n; i+=i&-i) seg[i]+=by; }
double sum(int at) {
    double ret=0.0;
    for(int i=at; i>=1; i-=i&-i) ret+=seg[i];
    return ret;
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        int x; scanf("%d", &x);
        v[x]=i;
    }

    for(int i=n; i>=1; i--) {
        ans += sum(v[i]);
        add(v[i],1);
    }

    memset(seg,0,sizeof(seg));
    for(int i=1; i<=n; i++) {
        ans += sum(v[i])*(n-v[i]+1)/n/(n+1);
        add(v[i],v[i]);
    }

    memset(seg,0,sizeof(seg));
    for(int i=n; i>=1; i--) {
        ans -= sum(v[i])*(n-v[i]+1)/n/(n+1);
        add(v[i],v[i]);
    }

    printf("%.9lf", ans);
    return 0;
}
