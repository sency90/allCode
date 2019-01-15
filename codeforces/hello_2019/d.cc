#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = ll(1e9)+7;
ll pow(int x, int n) {
    if(n==0) return 1LL;
    ll ret = pow(x,n>>1);
    ret = ret*ret%MOD;
    if(n%2 == 1) ret = ret*x%MOD;
    return ret;
}
int main() {
    int p=15, q=8;
    int res = p * pow(q,MOD-2) % MOD;
    printf("res: %d\n", res);
    return 0;
}
