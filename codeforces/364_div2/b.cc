#include <stdio.h>
#include <set>
using namespace std;
set<int> sx, sy;
int main() {
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &x,&y);
        sx.insert(x);
        sy.insert(y);
        printf("%lld ", (long long)(n-sx.size())*(n-sy.size()));
    }
    return 0;
}
