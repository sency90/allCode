#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll v[100001];
int main() {
    freopen("input.txt","r",stdin);
    freopen("output2.txt","w",stdout);
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &v[i]);
    }
    sort(v,v+n);
    for(int i=0;i <n; i++) {
        printf("%lld\n", v[i]);
    }
    return 0;
}
