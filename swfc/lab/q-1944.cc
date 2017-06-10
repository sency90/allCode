#include <iostream>
using namespace std;
typedef long long ll;
ll d[51];
ll f(int x) {
    if(x==1||x==2) return 1LL;
    if(d[x]) return d[x];
    return d[x]=f(x-1)+f(x-2);
}
int main() {
    int n; scanf("%d", &n);
    printf("%lld", f(n));
    return 0;
}
