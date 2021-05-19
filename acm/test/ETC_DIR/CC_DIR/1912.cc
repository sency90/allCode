#include <stdio.h>
#include <algorithm>
using namespace std;
int v[100001], d[100001];
int mx;
int f(int x) {
    if(x==1) return v[x];
    int &ret = d[x];
    ret = max(f(x-1)+v[x], v[x]);
    if(mx < ret) mx = ret;
    return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    mx=v[1]; f(n);
    printf("%d", mx);
    return 0;
}
