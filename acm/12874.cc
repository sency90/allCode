#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7LL;
int n;
ll d[101][51];
ll f(int x, int y) {
    ll &ret = d[x][y];
    if(ret!=-1) return ret;

    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    memset(d, -1, sizeof(d));
    printf("%lld", f(0,0));
    return 0;
}
