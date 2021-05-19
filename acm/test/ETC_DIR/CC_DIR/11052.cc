#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int d[1001], n;
int f(int x) {
    if(x==0) return 0;
    if(d[x]>0) return d[x];
    int &ret = d[x];
    for(int i=1; i<=n; i++) {
        if(x<i) break;
        ret = max(ret,f(x-i)+v[i]);
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    v.resize(n+1); v[0]=0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    printf("%d", f(n));
    return 0;
}
