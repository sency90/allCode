#include <cstdio>
#include <algorithm>
using namespace std;
int v[101];
int main() {
    int n;
    scanf("%d",&n);
    int mx=0;
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        mx=max(v[i],mx);
    }
    int ans=0;
    for(int i=0; i<n; i++) {
        ans+=(mx-v[i]);
    }
    printf("%d", ans);
    return 0;
}
