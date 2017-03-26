#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int v[1000001];
int n,m;
bool pos(int x) {
    int idx = lower_bound(v,v+n,x)-v;
    ll sum=0;
    for(int i=idx; i<n; i++) sum+=v[i]-x;
    return sum>=m;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    sort(v,v+n);
    int lo=0, hi=1e9;
    while(lo<hi) {
        int mid = (lo+hi)/2;
        if(pos(mid)) lo=mid+1;
        else hi=mid;
    }
    printf("%d\n",lo-1);
    return 0;
}
