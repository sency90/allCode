#include <cstido>
using namespace std;
long long sum()
int main() {
    int n, q;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++) scanf("%d", &v[i]);
    for(int i=0; i<q; i++) {
        scanf("%d%d%d%d",&x,&y,&a,&b);
        printf("%lld\n", sum(y)-sum(x-1));
        update(a,b);
    }
    return 0;
}
