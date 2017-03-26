#include <cstdio>
#include <algorithm>
using namespace std;
int inf = 0x3f3f3f3f;
int v[100001], mn=inf, mx=0;
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        mn=min(mn,v[i]);
        mx=max(mx,v[i]);
    }
    int cnt=0;
    for(int i=0; i<n; i++) {
        if(mn==v[i]) cnt++;
        else if(mx==v[i]) cnt++;
    }
    printf("%d", n-cnt);
    return 0;
}
