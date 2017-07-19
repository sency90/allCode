#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        ll x; scanf("%lld", &x);
        printf("%lld\n",abs(((x*567/9+7492)*235/47-498)/10)%10);
    }
    return 0;
}
