//여기서 13번째 줄 조심해야 함. v[i]<v[x] 가 아닐 때에도 f(i)는 호출해 줘야 한다.
#include <cstdio>
#include <algorithm>
using namespace std;
int d[1001], v[1001], mx=0;
int f(int x) {
    if(x==1) return 1;
    if(d[x]>0) return d[x];
    int pmx = 0;
    for(int i=x-1; i>=1; i--) {
        if(v[i]<v[x]) {
            pmx = max(pmx,f(i));
        } else f(i);
    }
    d[x] = pmx+1;
    if(mx < d[x]) mx = d[x];
    return d[x];
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    f(n);
    printf("%d", mx);
    return 0;
}
