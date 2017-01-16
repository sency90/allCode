#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
    int n; scanf("%d", &n);
    ll px,x,sum=0LL;
    scanf("%lld", &px);
    for(int i=1; i<n; i++) {
        scanf("%lld", &x);
        sum += px*x;
        px+=x;
    }
    printf("%lld", sum);
    return 0;
}
