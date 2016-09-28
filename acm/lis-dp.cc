#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n, d[1001];
int f(int x) {
    if(x==0) return d[x]=1;

    int &ret = d[x];
    if(ret!=0) return ret;
    else ret=1;
    for(int i=0; i<x; i++) {
        if(v[i]<v[x]) ret = max(ret, f(i)+1);
        else f(i);
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    v.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    f(n-1);
    int ans = 1;
    for(int i=0; i<n; i++) {
        ans = max(ans, d[i]);
    }
    printf("%d", ans);
    return 0;
}
