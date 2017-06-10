#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 20100529LL;
ll d[100001];
ll f(int x) {
    if(x<=1) return 1LL;
    if(d[x]) return d[x];
    return d[x] = (f(x-1) + 2*f(x-2))%mod;
}
int main() {
    int n; scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}
