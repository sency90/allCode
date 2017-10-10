#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,k;
    cin >> n >> k;
    long long ans= n/k;
    if(ans&1LL) puts("YES");
    else puts("NO");
    return 0;
}
