#include <stdio.h>
#include <algorithm>
using namespace std;
int d[10001], v[10001];
int f(int x) {
    if(x<0) return 0;
    if(x==0) return v[0];
    if(d[x]>0) return d[x];
    return d[x] = max(f(x-1)+v[x], f(x-2)+v[x-1]*v[x]);
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v, v+n);
    printf("%d", f(n-1));
    return 0;
}
