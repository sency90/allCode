#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int d[101];
int f(int x) {
    if(x<=1) return 1;
    int & ret = d[x];
    if(ret) return ret;

    return ret = (f(x-1) + f(x-2))%M;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        memset(d,0,sizeof(d));
        printf("%d\n", f(n));
    }
    return 0;
}