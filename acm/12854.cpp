#include <stdio.h>
#include <algorithm>
using namespace std;
int z[501];
int main() {
    int n,m,s,e,w;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &z[i]);
    }
    double mx = 0.0;
    for(int i=0; i<m; i++) {
        scanf("%d%d%d", &s,&e,&w);
        mx = max((double)(z[s]+z[e])/w, mx);
    }
    printf("%.6lf", mx);
    return 0;
}
