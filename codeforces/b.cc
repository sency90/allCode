#include <cstdio>
using namespace std;
typedef long long ll;
int f(ll k) {
    for(int i=0; i<52; i++) {
        if((1LL<<i) == k) return i+1;
        else if((1LL<<i)<k && k<(1LL<<(i+1))) return f(k-(1LL<<i));
    }
}
int main() {
    int n;
    ll k;
    scanf("%d%lld",&n,&k);
    printf("%d",f(k));
    return 0;
}
